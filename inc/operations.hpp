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

#ifndef INC_OPERATIONS_HPP_
#define INC_OPERATIONS_HPP_

#include <string>
#include <algorithm>

namespace operations {

class Operation {
 public:
    Operation(const std::string& op, const std::string& t)
        : option(op), text(t) {}

    virtual std::string& getOption() final { return option; }
    virtual std::string& getText() final { return text; }
    virtual std::string& operate() noexcept = 0;
    virtual ~Operation() = default;

 protected:
    std::string result;

 private:
    std::string option;
    std::string text;
};

class Casing : public Operation {
 public:
    Casing(const std::string& op, const std::string& t) : Operation(op, t) {}

    std::string& operate() noexcept override;

 private:
    std::string& lowercase();
    std::string& uppercase();
    std::string& togglecase();
    std::string& spongebobcase();
};

class Pattern : public Operation {
 public:
    Pattern(const std::string& op, size_t val, const std::string& t)
        : Operation(op, t), value(val) {}

    std::string& operate() noexcept override;

 private:
    std::string& reverse();
    std::string& spacing();
    std::string& wave();
    size_t value;
};

class Cipher : public Operation {
 public:
    Cipher(const std::string& op, size_t val, const std::string& t)
        : Operation(op, t), value(val) {}

    std::string& operate() noexcept override;

 private:
    std::string& atbash();
    std::string& caesar();
    const std::string ALPHABETS {"abcdefghijklmnopqrstuvwxyz"};
    size_t value;
};

}  // namespace operations

#endif  // INC_OPERATIONS_HPP_
