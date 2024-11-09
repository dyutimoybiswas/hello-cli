#ifndef INC_DISPLAY_HPP_
#define INC_DISPLAY_HPP_

#include <string>
#include <iostream>
#include <sstream>

namespace display {

class Display {
 public:
    static void output(const std::string&);
    static void help(const std::string&);
    static constexpr char SPACE_CHARACTER {' '};
    static constexpr char NEWLINE_CHARACTER {'\n'};

 private:
    enum LEADING_SPACES: size_t {
        CASINGS         = 11,
        PATTERNS        = 10,
        CIPHERS         = 11,
        TEXT            = 13,
        PATTERN_VALUE   = 3,
        CIPHER_VALUE    = 4,
        HELP            = 13,
        DEFAULT         = 5
    };

    Display() = default;
    static void helpCasing(std::ostringstream&);
    static void helpPattern(std::ostringstream&);
    static void helpCipher(std::ostringstream&);
    static void helpText(std::ostringstream&);
    static void helpPatternValue(std::ostringstream&);
    static void helpCipherValue(std::ostringstream&);
};

}   // namespace display

#endif  // INC_DISPLAY_HPP_
