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

#include <vector>
#include "operations.hpp"
#include "display.hpp"

namespace operations {

    std::string& Casing::Operate() noexcept {
        if (GetOption() == "lowercase")
            return LowerCase();

        if (GetOption() == "uppercase")
            return UpperCase();

        if (GetOption() == "togglecase")
            return ToggleCase();

        return SpongeBobCase();
    }

    std::string& Casing::LowerCase() {
        for (char ch : GetText())
            result.push_back(tolower(ch));

        return result;
    }

    std::string& Casing::UpperCase() {
        for (char ch : GetText())
            result.push_back(toupper(ch));

        return result;
    }

    std::string& Casing::ToggleCase() {
        for (char ch : GetText()) {
            char converted = ch;
            if (islower(ch))
                converted = toupper(ch);
            else if (isupper(ch))
                converted = tolower(ch);
            result.push_back(converted);
        }

        return result;
    }

    std::string& Casing::SpongeBobCase() {
        for (size_t i = 0; i < GetText().length(); ++i) {
            char converted = GetText()[i];

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

    std::string& Pattern::Operate() noexcept {
        if (GetOption() == "reverse")
            return Reverse();

        if (GetOption() == "spacing")
            return Spacing();

        return Wave();
    }

    std::string& Pattern::Reverse() {
        for (decltype(GetText().crbegin()) itr = GetText().crbegin();
             itr != GetText().crend(); ++itr)
            result.push_back(*itr);

        return result;
    }

    std::string& Pattern::Spacing() {
        const std::string& spaces = std::string(value,
                                    display::Display::kSpaceCharacter);

        for (char ch : GetText()) {
            result += ch;
            result.append(spaces);
        }

        return result;
    }

    std::string& Pattern::Wave() {
        if (!value)
            return GetText();

        size_t numRows {2 * value + 1};
        size_t currentRow {value};
        int direction {-1};
        std::vector<std::string> rows(numRows,
                                      std::string(GetText().length() * 2,
                                      display::Display::kSpaceCharacter));

        for (size_t col = 0; col < GetText().length(); ++col) {
            rows[currentRow][col * 2] = GetText()[col];
            currentRow += direction;

            if (currentRow == 0 || currentRow == numRows - 1)
                direction = -direction;
        }

        for (const std::string& row : rows)
            result.append(row + display::Display::kNewlineCharacter);

        return result;
    }

    std::string& Cipher::Operate() noexcept {
        if (GetOption() == "atbash")
            return Atbash();

        return Caesar();
    }

    std::string& Cipher::Atbash() {
        for (char ch : GetText()) {
            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {kAlphabets.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                modifiedIndex = kAlphabets.size() - 1 - modifiedIndex;
                toModify = isupper(ch) ? toupper(kAlphabets[modifiedIndex]) :
                                         kAlphabets[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }

    std::string& Cipher::Caesar() {
        for (char ch : GetText()) {
            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {kAlphabets.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                modifiedIndex = (modifiedIndex + value) % kAlphabets.size();
                toModify = isupper(ch) ? toupper(kAlphabets[modifiedIndex]) :
                                         kAlphabets[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }

}   // namespace operations
