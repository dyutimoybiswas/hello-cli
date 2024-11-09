#include "../inc/display.hpp"

namespace display {

void Display::output(const std::string& message) {
    std::ostringstream messageText(message);

    // Top padding.
    messageText << display::Display::NEWLINE_CHARACTER;
    messageText << message << display::Display::NEWLINE_CHARACTER;

    // Bottom padding.
    messageText << display::Display::NEWLINE_CHARACTER;
    std::cout << messageText.str();
}

void Display::help(const std::string& argument) {
    std::ostringstream helpText;

    helpText << "usage: hello-cli <operation> [text]"
             << std::string(2, display::Display::NEWLINE_CHARACTER);

    helpText << "Display entered text in specified styles,"
             << " viz. casings, patterns and ciphers. Outputs "
             << "\'Hello, CLI!\' when no options are provided."
             << std::string(2, display::Display::NEWLINE_CHARACTER);

    helpText << "operations:" << display::Display::NEWLINE_CHARACTER;

    if (argument.empty()) {
        display::Display::helpCasing(helpText);
        display::Display::helpPattern(helpText);
        display::Display::helpCipher(helpText);
        display::Display::helpText(helpText);
        display::Display::helpPatternValue(helpText);
        display::Display::helpCipherValue(helpText);

        // help.
        helpText << std::string(Display::LEADING_SPACES::DEFAULT,
                                Display::SPACE_CHARACTER) << "--help, -h"
                 << std::string(Display::LEADING_SPACES::HELP,
                                Display::SPACE_CHARACTER)
                 << "display help on how to use."
                 << display::Display::NEWLINE_CHARACTER;
    } else {
        if (argument == "--casing") {
            display::Display::helpCasing(helpText);
        } else if (argument == "--pattern") {
            display::Display::helpPattern(helpText);
            display::Display::helpPatternValue(helpText);
        } else if (argument == "--cipher") {
            display::Display::helpCipher(helpText);
            display::Display::helpCipherValue(helpText);
        } else if (argument == "--text") {
            display::Display::helpText(helpText);
        } else if (argument == "--pattern-value") {
            display::Display::helpPatternValue(helpText);
        } else if (argument == "--cipher-value") {
            display::Display::helpCipherValue(helpText);
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
       << display::Display::NEWLINE_CHARACTER;
}

void Display::helpPattern(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--pattern, -p"
       << std::string(Display::LEADING_SPACES::PATTERNS,
                      Display::SPACE_CHARACTER)
       << "specify pattern in which to display the output. Possible values are"
       << " \'reverse\', \'spacing\' and \'wave\'."
       << " See below for more info on \'spacing\' and \'wave\'."
       << display::Display::NEWLINE_CHARACTER;
}

void Display::helpCipher(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--cipher, -C"
       << std::string(Display::LEADING_SPACES::CIPHERS,
                      Display::SPACE_CHARACTER)
       << "specify cipher in which to encrypt the output. Possible values are"
       << " \'caesar\' and \'atbash\'." << display::Display::NEWLINE_CHARACTER;
}

void Display::helpText(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--text, -t"
       << std::string(Display::LEADING_SPACES::TEXT, Display::SPACE_CHARACTER)
       << "the input text to stylize." << display::Display::NEWLINE_CHARACTER;
}

void Display::helpPatternValue(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--pattern-value, -pv"
       << std::string(Display::LEADING_SPACES::PATTERN_VALUE,
                      Display::SPACE_CHARACTER)
       << "optionally specify values for \'spacing\' (spaces) or \'wave\'"
       << " (amplitude) patterns."
       << display::Display::NEWLINE_CHARACTER;
}

void Display::helpCipherValue(std::ostringstream& os) {
    os << std::string(Display::LEADING_SPACES::DEFAULT,
                      Display::SPACE_CHARACTER) << "--cipher-value, -Cv"
       << std::string(Display::LEADING_SPACES::CIPHER_VALUE,
                      Display::SPACE_CHARACTER)
       << "optionally specify values for \'caesar\' (shift) cipher."
       << display::Display::NEWLINE_CHARACTER;
}
}   // namespace display
