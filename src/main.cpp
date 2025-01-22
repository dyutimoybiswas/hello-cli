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

#include <iostream>
#include "../inc/inputhandler.hpp"

int main(int argc, char const *argv[]) {
    try {
        inputhandler::InputHandler handler(argc, argv);
        handler.ProcessInput();
    } catch (std::invalid_argument& ie) {
        std::cerr << "Invalid argument: " << ie.what() << std::endl;
    } catch (std::logic_error& le) {
        std::cerr << "Input error: " << le.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unknown error: " << e.what() << std::endl;
    }

    return 0;
}
