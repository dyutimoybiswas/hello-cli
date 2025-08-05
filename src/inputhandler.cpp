// MIT License
//
// Copyright (c) 2024-2025 Dyutimoy Biswas
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

#include <memory>
#include <stdexcept>
#include "../inc/inputhandler.hpp"
#include "../inc/display.hpp"
#include "../inc/operations.hpp"

namespace inputhandler {

InputHandler::InputHandler(int argc, const char* argv[]): args_{}, ops_{} {
    for (int i = 1; i < argc; ++i) {
        args_.push_back(std::move(argv[i]));
    }
}

void InputHandler::ProcessInput() {
    std::string last_argument;
    std::string text;
    std::unique_ptr<operations::Operation> op;
    size_t i {0};
    size_t cipher_value {3};
    size_t pattern_value {1};
    bool is_text_flag_provided {false};

    for (; i < args_.size(); i += 2) {
        if (args_[i] == "-h" || args_[i] == "--help") {
            display::Display::Help(last_argument);
            return;
        }

        if (args_[i] == "-t" || args_[i] == "--text") {
            if (last_argument.empty()) {
                throw std::logic_error(
                    "Please specify type of operation before providing text.");
            }

            is_text_flag_provided = true;
            break;
        }

        if (args_[i] == "-c" || args_[i] == "--casing") {
            last_argument = "--casing";

            if (i + 1 == args_.size()) {
                throw std::logic_error(
                    "Value for specified operation cannot be empty.");
            }

            if (args_[i + 1] == "-h" || args_[i + 1] == "--help") {
                display::Display::Help(last_argument);
                return;
            }

            ValidateOperation(last_argument, args_[i + 1]);
        } else if (args_[i] == "-p" || args_[i] == "--pattern") {
            last_argument = "--pattern";

            if (i + 1 == args_.size()) {
                throw std::logic_error(
                    "Value for specified operation cannot be empty.");
            }

            if (args_[i + 1] == "-h" || args_[i + 1] == "--help") {
                display::Display::Help(last_argument);
                return;
            }

            ValidateOperation(last_argument, args_[i + 1]);
        } else if (args_[i] == "-pv" || args_[i] == "--pattern-value") {
            last_argument = "--pattern-value";

            if (i + 1 == args_.size()) {
                throw std::logic_error(
                    "Value for specified operation cannot be empty.");
            }

            if (args_[i + 1] == "-h" || args_[i + 1] == "--help") {
                display::Display::Help(last_argument);
                return;
            }

            ValidateValue(last_argument, args_[i + 1]);
            pattern_value = std::stoul(args_[i + 1]);

        } else if (args_[i] == "-Cv" || args_[i] == "--cipher-value") {
            last_argument = "--cipher-value";

            if (i + 1 == args_.size()) {
                throw std::logic_error(
                    "Value for specified operation cannot be empty.");
            }

            if (args_[i + 1] == "-h" || args_[i + 1] == "--help") {
                display::Display::Help(last_argument);
                return;
            }

            ValidateValue(last_argument, args_[i + 1]);
            cipher_value = std::stoul(args_[i + 1]);

        } else if (args_[i] == "-C" || args_[i] == "--cipher") {
            last_argument = "--cipher";

            if (i + 1 == args_.size()) {
                throw std::logic_error(
                    "Value for specified operation cannot be empty.");
            }

            if (args_[i + 1] == "-h" || args_[i + 1] == "--help") {
                display::Display::Help(last_argument);
                return;
            }

            ValidateOperation(last_argument, args_[i + 1]);
        } else {
            throw std::logic_error("Please specify a valid operation.");
        }
    }

    if (is_text_flag_provided) {
        for (; i < args_.size() - 1; ++i) {
            text.append(std::move(args_[i + 1]));
            text.push_back(display::Display::kSpaceCharacter);
        }

        if (text.empty()) {
            throw std::logic_error("Text cannot be empty.");
        }

        if (text == "-h " || text == "--help ") {
            display::Display::Help("--text");
            return;
        }
    } else {
        text = "Hello, CLI!";   // default text.
    }

    for (auto itr = ops_.cbegin(); itr != ops_.cend(); ++itr) {
        if (itr->first == "--casing") {
            op = std::make_unique<operations::Casing>(itr->second, text);
        } else if (itr->first == "--pattern") {
            op = std::make_unique<operations::Pattern>(itr->second,
                                                       pattern_value, text);
        } else if (itr->first == "--cipher") {
            op = std::make_unique<operations::Cipher>(itr->second,
                                                      cipher_value, text);
        } else if (itr->first == "--pattern-value" ||
                 itr->first == "--cipher-value") {
            continue;
        }

        text = std::move(op->Operate());
    }

    display::Display::Output(text);
}

void InputHandler::ValidateOperation(const std::string& op,
                                     const std::string& choice) {
    if (ops_.find(op) != ops_.end()) {
        throw std::logic_error("Operation(s) cannot be repeated.");
    }

    std::vector<std::string> valid_values = kValidMappings.find(op)->second;

    if (!std::any_of(valid_values.cbegin(), valid_values.cend(),
                     [choice](const std::string& value) -> bool
                     { return value == choice; })) {
        throw std::invalid_argument(
            "Value entered for the given operation is incorrect.");
    }

    ops_.insert(std::make_pair(op, choice));
}

void InputHandler::ValidateValue(const std::string& op,
                                 const std::string& value) {
    if (ops_.find(op) != ops_.end()) {
        throw std::logic_error("Operation(s) cannot be repeated.");
    }

    for (char ch : value) {
        if (ch != '-' && ch != '+' && !isdigit(ch)) {
            throw std::invalid_argument("Value must be numeric.");
        }
    }

    try {
        if (std::stoi(value) < 0) {
            throw std::invalid_argument("Value cannot be negative.");
        }
    } catch (const std::out_of_range&) {
        throw std::invalid_argument("Value is too large.");
    }

    ops_.insert(std::make_pair(op, value));
}

}   // namespace inputhandler
