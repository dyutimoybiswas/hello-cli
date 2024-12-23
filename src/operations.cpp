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

#include <vector>
#include "../inc/operations.hpp"
#include "../inc/display.hpp"

namespace operations {

    std::string& Casing::operate() noexcept {
        if (getOption() == "lowercase")
            return lowercase();

        if (getOption() == "uppercase")
            return uppercase();

        if (getOption() == "togglecase")
            return togglecase();

        return spongebobcase();
    }

    std::string& Casing::lowercase() {
        for (char ch : getText())
            result.push_back(tolower(ch));

        return result;
    }

    std::string& Casing::uppercase() {
        for (char ch : getText())
            result.push_back(toupper(ch));

        return result;
    }

    std::string& Casing::togglecase() {
        for (char ch : getText()) {
            char converted = ch;
            if (islower(ch))
                converted = toupper(ch);
            else if (isupper(ch))
                converted = tolower(ch);
            result.push_back(converted);
        }

        return result;
    }

    std::string& Casing::spongebobcase() {
        for (size_t i = 0; i < getText().length(); ++i) {
            char converted = getText()[i];

            if (!(i % 2) || !(i % 7) || !(i % 9)) {
                if (islower(converted))
                    converted = toupper(converted);
                else if (isupper(converted))
                    converted = tolower(converted);
            }

            result.push_back(converted);
        }

        return result;
    }

    std::string& Pattern::operate() noexcept {
        if (getOption() == "reverse")
            return reverse();

        if (getOption() == "spacing")
            return spacing();

        return wave();
    }

    std::string& Pattern::reverse() {
        for (decltype(getText().crbegin()) itr = getText().crbegin();
             itr != getText().crend(); ++itr)
            result.push_back(*itr);

        return result;
    }

    std::string& Pattern::spacing() {
        const std::string& spaces = std::string(value,
                                    display::Display::SPACE_CHARACTER);

        for (char ch : getText()) {
            result += ch;
            result.append(spaces);
        }

        return result;
    }

    std::string& Pattern::wave() {
        if (!value)
            return getText();

        size_t numRows {2 * value + 1};
        size_t currentRow {value};
        int direction {-1};
        std::vector<std::string> rows(numRows,
                                      std::string(getText().length() * 2,
                                      display::Display::SPACE_CHARACTER));

        for (size_t col = 0; col < getText().length(); ++col) {
            rows[currentRow][col * 2] = getText()[col];
            currentRow += direction;

            if (currentRow == 0 || currentRow == numRows - 1)
                direction = -direction;
        }

        for (const std::string& row : rows)
            result.append(row + display::Display::NEWLINE_CHARACTER);

        return result;
    }

    std::string& Cipher::operate() noexcept {
        if (getOption() == "atbash")
            return atbash();

        return caesar();
    }

    std::string& Cipher::atbash() {
        for (char ch : getText()) {
            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {ALPHABETS.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                modifiedIndex = ALPHABETS.size() - 1 - modifiedIndex;
                toModify = isupper(ch) ? toupper(ALPHABETS[modifiedIndex]) :
                                         ALPHABETS[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }

    std::string& Cipher::caesar() {
        for (char ch : getText()) {
            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {ALPHABETS.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                modifiedIndex = (modifiedIndex + value) % ALPHABETS.size();
                toModify = isupper(ch) ? toupper(ALPHABETS[modifiedIndex]) :
                                         ALPHABETS[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }

}   // namespace operations
