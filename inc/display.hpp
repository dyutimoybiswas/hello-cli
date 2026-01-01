// MIT License
//
// Copyright (c) 2024-2026 Dyutimoy Biswas
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
    static void Output(const std::string&);
    static void Help(const std::string&);
    static constexpr char kSpaceCharacter {' '};
    static constexpr char kNewlineCharacter {'\n'};

 private:
    enum kLeadingSpaces : size_t {
        kPatternValue   = 3,
        kCipherValue    = 4,
        kDefault        = 5,
        kPatterns       = 10,
        kCasings        = 11,
        kCiphers        = 11,
        kText           = 13,
        kHelp           = 13
    };

    static void HelpCasing(std::ostringstream&);
    static void HelpPattern(std::ostringstream&);
    static void HelpCipher(std::ostringstream&);
    static void HelpText(std::ostringstream&);
    static void HelpPatternValue(std::ostringstream&);
    static void HelpCipherValue(std::ostringstream&);
};

}  // namespace display

#endif  // INC_DISPLAY_HPP_
