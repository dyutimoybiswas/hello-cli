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

#ifndef INC_INPUTHANDLER_HPP_
#define INC_INPUTHANDLER_HPP_

#include <unordered_map>
#include <vector>
#include <string>
#include <stdexcept>

namespace inputhandler {

class InputHandler {
 public:
    InputHandler(int argc, const char* argv[]);
    void processInput();

 private:
    const std::unordered_map<std::string, std::vector<std::string>>
    validMappings = {
        {"--casing", {"lowercase", "uppercase", "togglecase", "spongebobcase"}},
        {"--pattern", {"reverse", "spacing", "wave"}},
        {"--cipher", {"atbash", "caesar"}}
    };

    std::vector<std::string> args;
    std::unordered_map<std::string, std::string> ops;

    void validateOperation(const std::string&, const std::string&);
    void validateValue(const std::string&, const std::string&);
};

}  // namespace inputhandler

#endif  // INC_INPUTHANDLER_HPP_
