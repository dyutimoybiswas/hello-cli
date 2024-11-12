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
    enum LEADING_SPACES : size_t {
        CASINGS        = 11,
        PATTERNS       = 10,
        CIPHERS        = 11,
        TEXT           = 13,
        PATTERN_VALUE  = 3,
        CIPHER_VALUE   = 4,
        HELP           = 13,
        DEFAULT        = 5
    };

    Display() = default;

    static void helpCasing(std::ostringstream&);
    static void helpPattern(std::ostringstream&);
    static void helpCipher(std::ostringstream&);
    static void helpText(std::ostringstream&);
    static void helpPatternValue(std::ostringstream&);
    static void helpCipherValue(std::ostringstream&);
};

}  // namespace display

#endif  // INC_DISPLAY_HPP_
