// MIT License
//
// Copyright (c) 2024 Dyutimoy Biswas
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

#include "../inc/display.hpp"

namespace display {

void Display::output(const std::string& message) {
    std::ostringstream messageText(message);

    // Top padding.
    messageText << Display::NEWLINE_CHARACTER;
    messageText << message << Display::NEWLINE_CHARACTER;

    // Bottom padding.
    messageText << Display::NEWLINE_CHARACTER;

    std::cout << messageText.str();
}

void Display::help(const std::string& argument) {
    std::ostringstream helpText;

    helpText << "usage: hello-cli <operation> [text]"
             << std::string(2, Display::NEWLINE_CHARACTER);

    helpText << "Display entered text in specified styles,"
             << " viz. casings, patterns and ciphers. Outputs "
             << "\'Hello, CLI!\' when no options are provided."
             << std::string(2, Display::NEWLINE_CHARACTER);

    helpText << "operations:" << Display::NEWLINE_CHARACTER;

    if (argument.empty()) {
        Display::helpCasing(helpText);
        Display::helpPattern(helpText);
        Display::helpCipher(helpText);
        Display::helpText(helpText);
        Display::helpPatternValue(helpText);
        Display::helpCipherValue(helpText);

        // help.
        helpText << std::string(Display::LEADING_SPACES::DEFAULT,
                                Display::SPACE_CHARACTER) << "--help, -h"
                 << std::string(Display::LEADING_SPACES::HELP,
                                Display::SPACE_CHARACTER)
                 << "display help on how to use."
                 << Display::NEWLINE_CHARACTER;
    } else {
        if (argument == "--casing") {
            Display::helpCasing(helpText);
        } else if (argument == "--pattern") {
            Display::helpPattern(helpText);
            Display::helpPatternValue(helpText);
        } else if (argument == "--cipher") {
            Display::helpCipher(helpText);
            Display::helpCipherValue(helpText);
        } else if (argument == "--text") {
            Display::helpText(helpText);
        } else if (argument == "--pattern-value") {
            Display::helpPatternValue(helpText);
        } else if (argument == "--cipher-value") {
            Display::helpCipherValue(helpText);
        }
    }

    std::cout << helpText.str();
}

void Display::helpCasing(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--casing, -c"
       << std::string(Display::LEADING_SPACES::CASINGS,
                      Display::SPACE_CHARACTER)
       << "specify casing to be followed when displaying the output."
       << " Possible values are"
       << " \'lowercase\', \'uppercase\', \'togglecase\' and \'spongebobcase\'."
       << Display::NEWLINE_CHARACTER;
}

void Display::helpPattern(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--pattern, -p"
       << std::string(Display::LEADING_SPACES::PATTERNS,
                      Display::SPACE_CHARACTER)
       << "specify pattern in which to display the output. Possible values are"
       << " \'reverse\', \'spacing\' and \'wave\'."
       << " See below for more info on \'spacing\' and \'wave\'."
       << Display::NEWLINE_CHARACTER;
}

void Display::helpCipher(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--cipher, -C"
       << std::string(Display::LEADING_SPACES::CIPHERS,
                      Display::SPACE_CHARACTER)
       << "specify cipher in which to encrypt the output. Possible values are"
       << " \'caesar\' and \'atbash\'." << Display::NEWLINE_CHARACTER;
}

void Display::helpText(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--text, -t"
       << std::string(Display::LEADING_SPACES::TEXT, Display::SPACE_CHARACTER)
       << "the input text to stylize." << Display::NEWLINE_CHARACTER;
}

void Display::helpPatternValue(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--pattern-value, -pv"
       << std::string(Display::LEADING_SPACES::PATTERN_VALUE,
                      Display::SPACE_CHARACTER)
       << "optionally specify values for \'spacing\' (spaces) or \'wave\'"
       << " (amplitude) patterns."
       << Display::NEWLINE_CHARACTER;
}

void Display::helpCipherValue(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--cipher-value, -Cv"
       << std::string(Display::LEADING_SPACES::CIPHER_VALUE,
                      Display::SPACE_CHARACTER)
       << "optionally specify values for \'caesar\' (shift) cipher."
       << Display::NEWLINE_CHARACTER;
}

}   // namespace display
