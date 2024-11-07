#include "display.hpp"

namespace display {

    void Display::output(const std::string& message) {

        std::cout << std::endl;     // Top padding.
        std::cout << message << std::endl;
        std::cout << std::endl;     // Bottom padding.
    }

    void Display::help() {

        std::cout << "usage: hello-cli <operation> [...]" << std::endl;
        std::cout << std::endl;
        std::cout << "Display entered text in specified styles,"
                  << " viz. casings, patterns and ciphers. Outputs "
                  << "\'Hello, CLI!\' when no options are provided." << std::endl;
        std::cout << std::endl;
        std::cout << "operations:" << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--casing, -c" << std::string(Display::LEADING_SPACES::CASING, Display::SPACE_CHARACTER)
                  << "specify casing to be followed when displaying the output. Possible values are"
                  << " \'lowercase\', \'uppercase\', \'togglecase\' and \'spongebobcase\'." << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--patterns, -p" << std::string(Display::LEADING_SPACES::PATTERNS, Display::SPACE_CHARACTER)
                  << "specify pattern in which to display the output. Possible values are"
                  << " \'reverse\', \'spacing\' and \'wave\'. See below for more info on \'spacing\' and \'wave\'."
                  << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--cipher, -C" << std::string(Display::LEADING_SPACES::CIPHER, Display::SPACE_CHARACTER)
                  << "specify cipher in which to encrypt the output. Possible values are"
                  << " \'caesar\' and \'atbash\'." << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--text, -t" << std::string(Display::LEADING_SPACES::TEXT, Display::SPACE_CHARACTER)
                  << "the input text to stylize." << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--value, -v" << std::string(Display::LEADING_SPACES::VALUE, Display::SPACE_CHARACTER)
                  << "specify values for \'spacing\' (spaces), \'wave\' (amplitude) patterns and \'caesar\' (shift) cipher."
                  << " Cannot be used with any other style." << std::endl;

        std::cout << std::string(Display::LEADING_SPACES::DEFAULT, Display::SPACE_CHARACTER) << "--help, -h" << std::string(Display::LEADING_SPACES::HELP, Display::SPACE_CHARACTER)
                  << "display help on how to use." << std::endl;
    }

}
