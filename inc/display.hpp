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
                CASING   = 5,
                PATTERNS = 3,
                CIPHER   = 5,
                TEXT     = 7,
                VALUE    = 6,
                HELP     = 7,
                DEFAULT  = 10
            };
            Display() = default;
    };

}

#endif
