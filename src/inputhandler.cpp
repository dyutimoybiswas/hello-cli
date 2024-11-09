#include <memory>
#include <stdexcept>
#include "inputhandler.hpp"
#include "display.hpp"
#include "operations.hpp"

namespace inputhandler {

    InputHandler::InputHandler(int argc, const char* argv[]) {

        for (int i = 1; i < argc; ++i)
            args.push_back(argv[i]);
    }

    void InputHandler::processInput() {

        // Output help text.
        if (!args.empty() && (args.front() == "--help" || args.front() == "-h"))
            display::Display::help();
        
        else {
            std::string lastArgument;
            std::string text;
            std::unique_ptr<operations::Operation> op;
            size_t i {0};
            size_t cipherValue {3};
            size_t patternValue {1};
            bool isTextFlagProvided {false};

            for (; i < args.size(); i += 2) {
                
                if (args[i] == "-t" || args[i] == "--text") {

                    if (lastArgument.empty())
                        throw std::logic_error("Please specify type of operation before providing text.");                    
                    
                    else {
                        isTextFlagProvided = true;
                        break;
                    }
                }

                if (args[i] == "-c" || args[i] == "--casing") {

                    lastArgument = "--casing";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    validateOperation(lastArgument, args[i + 1]);

                } else if (args[i] == "-p" || args[i] == "--pattern") {

                    lastArgument = "--pattern";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    validateOperation(lastArgument, args[i + 1]);

                } else if (args[i] == "-pv" || args[i] == "--pattern-value") {

                    lastArgument = "--pattern-value";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    validateValue(lastArgument, args[i + 1]);
                    patternValue = std::stoul(args[i + 1]);

                } else if (args[i] == "-Cv" || args[i] == "--cipher-value") {

                    lastArgument = "--cipher-value";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    validateValue(lastArgument, args[i + 1]);
                    cipherValue = std::stoul(args[i + 1]);

                } else if (args[i] == "-C" || args[i] == "--cipher") {

                    lastArgument = "--cipher";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    validateOperation(lastArgument, args[i + 1]);

                } else
                    throw std::logic_error("Please specify a valid operation.");
            }

            if (isTextFlagProvided) {

                for (; i < args.size() - 1; ++i) {
                
                    text.append(args[i + 1]);
                    text.append(" ");
                }

                if (text.empty())
                    throw std::logic_error("Text cannot be empty.");
            } else
                text = "Hello, CLI!";   // default text.

            for (auto itr = ops.cbegin(); itr != ops.cend(); ++itr) {

                if (itr->first == "--casing")
                    op = std::make_unique<operations::Casing>(itr->second, text);
                
                else if (itr->first == "--pattern")
                    op = std::make_unique<operations::Pattern>(itr->second, patternValue, text);

                else if (itr->first == "--cipher")
                    op = std::make_unique<operations::Cipher>(itr->second, cipherValue, text);

                else if (itr->first == "--pattern-value" || itr->first == "--cipher-value")
                    continue;

                text = op.get()->operate();
            }

            display::Display::output(text);
        }
    }

    void InputHandler::validateOperation(const std::string& op, const std::string& choice) {

        if (ops.find(op) != ops.end())
            throw std::logic_error("Operation(s) cannot be repeated.");

        std::vector<std::string> validValues = validMappings.find(op)->second;

        if (!std::any_of(validValues.cbegin(), validValues.cend(), [choice](const std::string& value) -> bool { return value == choice; }))
            throw std::invalid_argument("Value entered for the given operation is incorrect.");

        ops.insert(std::make_pair(op, choice));
    }

    void InputHandler::validateValue(const std::string& op, const std::string& value) {

        if (ops.find(op) != ops.end())
            throw std::logic_error("Operation(s) cannot be repeated.");

        for (char ch: value)
            if (ch != '-' && ch != '+' && !isdigit(ch))
                throw std::invalid_argument("Value must be numeric.");

        if (std::stoi(value) < 0)
            throw std::invalid_argument("Value cannot be negative.");

        ops.insert(std::make_pair(op, value));
    }
}
