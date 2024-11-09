#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <string>
#include <iostream>
#include <iomanip>

namespace display {

    class Display {

        public:

            static void output(const std::string&);
            static void help();
            static constexpr char SPACE_CHARACTER {' '};

        private:

            enum LEADING_SPACES: size_t {
                CASING          = 11,
                PATTERNS        = 9,
                CIPHER          = 11,
                TEXT            = 13,
                PATTERN_VALUE   = 3,
                CIPHER_VALUE    = 4,
                HELP            = 13,
                DEFAULT         = 16
            };
            Display() = default;
    };

}

#endif
