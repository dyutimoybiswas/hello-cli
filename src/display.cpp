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

#include "../inc/display.hpp"

namespace display {

void Display::Output(const std::string& message) {
    std::ostringstream message_text(message);

    // Top padding.
    message_text << Display::kNewlineCharacter;
    message_text << message << Display::kNewlineCharacter;

    // Bottom padding.
    message_text << Display::kNewlineCharacter;

    std::cout << message_text.str();
}

void Display::Help(const std::string& argument) {
    std::ostringstream help_text;

    help_text << "usage: hello-cli <operation> [text]"
             << std::string(2, Display::kNewlineCharacter);

    help_text << "Display entered text in specified styles,"
             << " viz. casings, patterns and ciphers. Outputs "
             << "\'Hello, CLI!\' when no options are provided."
             << std::string(2, Display::kNewlineCharacter);

    help_text << "operations:" << Display::kNewlineCharacter;

    if (argument.empty()) {
        Display::HelpCasing(help_text);
        Display::HelpPattern(help_text);
        Display::HelpCipher(help_text);
        Display::HelpText(help_text);
        Display::HelpPatternValue(help_text);
        Display::HelpCipherValue(help_text);

        // help.
        help_text << std::string(Display::kLeadingSpaces::kDefault,
                                Display::kSpaceCharacter) << "--help, -h"
                 << std::string(Display::kLeadingSpaces::kHelp,
                                Display::kSpaceCharacter)
                 << "display help on how to use."
                 << Display::kNewlineCharacter;
    } else {
        if (argument == "--casing") {
            Display::HelpCasing(help_text);
        } else if (argument == "--pattern") {
            Display::HelpPattern(help_text);
            Display::HelpPatternValue(help_text);
        } else if (argument == "--cipher") {
            Display::HelpCipher(help_text);
            Display::HelpCipherValue(help_text);
        } else if (argument == "--text") {
            Display::HelpText(help_text);
        } else if (argument == "--pattern-value") {
            Display::HelpPatternValue(help_text);
        } else if (argument == "--cipher-value") {
            Display::HelpCipherValue(help_text);
        }
    }

    std::cout << help_text.str();
}

void Display::HelpCasing(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--casing, -c"
       << std::string(Display::kLeadingSpaces::kCasings,
                      Display::kSpaceCharacter)
       << "specify casing to be followed when displaying the output."
       << " Possible values are"
       << " \'lowercase\', \'uppercase\', \'togglecase\' and \'spongebobcase\'."
       << Display::kNewlineCharacter;
}

void Display::HelpPattern(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--pattern, -p"
       << std::string(Display::kLeadingSpaces::kPatterns,
                      Display::kSpaceCharacter)
       << "specify pattern in which to display the output. Possible values are"
       << " \'reverse\', \'spacing\' and \'wave\'."
       << " See below for more info on \'spacing\' and \'wave\'."
       << Display::kNewlineCharacter;
}

void Display::HelpCipher(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--cipher, -C"
       << std::string(Display::kLeadingSpaces::kCiphers,
                      Display::kSpaceCharacter)
       << "specify cipher in which to encrypt the output. Possible values are"
       << " \'caesar\' and \'atbash\'." << Display::kNewlineCharacter;
}

void Display::HelpText(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--text, -t"
       << std::string(Display::kLeadingSpaces::kText, Display::kSpaceCharacter)
       << "the input text to stylize." << Display::kNewlineCharacter;
}

void Display::HelpPatternValue(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--pattern-value, -pv"
       << std::string(Display::kLeadingSpaces::kPatternValue,
                      Display::kSpaceCharacter)
       << "optionally specify values for \'spacing\' (spaces) or \'wave\'"
       << " (amplitude) patterns."
       << Display::kNewlineCharacter;
}

void Display::HelpCipherValue(std::ostringstream& os) {
    os << std::string(Display::kLeadingSpaces::kDefault,
                      Display::kSpaceCharacter) << "--cipher-value, -Cv"
       << std::string(Display::kLeadingSpaces::kCipherValue,
                      Display::kSpaceCharacter)
       << "optionally specify values for \'caesar\' (shift) cipher."
       << Display::kNewlineCharacter;
}

}   // namespace display
