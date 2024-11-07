#include <vector>
#include "operations.hpp"
#include "display.hpp"

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

        for (char ch: getText())
            result.push_back(tolower(ch));
        
        return result;
    }

    std::string& Casing::uppercase() {

        for (char ch: getText())
            result.push_back(toupper(ch));
        
        return result;
    }

    std::string& Casing::togglecase() {

        for (char ch: getText()) {
            char converted = ch;
            if (islower(ch))
                converted = toupper(ch);
            else if (isupper(ch))
                converted = tolower(ch);
            result.push_back(converted);
        }
        
        return result;
    }

    // Toggle case when index is multiple of 2, 7 or 9.
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

        for (decltype(getText().crbegin()) itr = getText().crbegin(); itr != getText().crend(); ++itr)
            result.push_back(*itr);

        return result;
    }

    std::string& Pattern::spacing() {

        const std::string& spaces = std::string(value, display::Display::SPACE_CHARACTER);

        for (char ch: getText()) {
            result += ch;
            result.append(spaces);
        }

        return result;
    }

    std::string& Pattern::wave() {

        size_t period {2 * value};
        size_t numRows {period + 1} ;
        size_t spaces {getText().length() * 2};
        size_t currentRow {value};
        bool movingUp {true};
        std::vector<std::string> rows(numRows, std::string(spaces, display::Display::SPACE_CHARACTER));

        for (size_t col {0}; col < getText().length(); ++col) {

            rows[currentRow][col * 2] = getText()[col];

            if (movingUp) {

                if (currentRow > 0)
                    --currentRow;
                if (currentRow == 0)
                    movingUp = false;

            } else {

                if (currentRow < numRows - 1)
                    ++currentRow;
                if (currentRow == numRows - 1)
                    movingUp = true;
            }
        }

        for (const std::string& row: rows)
            result.append(row + "\n");

        return result;
    }

    std::string& Cipher::operate() noexcept {

        if (getOption() == "atbash")
            return atbash();

        return caesar();
    }

    std::string& Cipher::atbash() {

        for (char ch: getText()) {

            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {ALPHABETS.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                
                modifiedIndex = ALPHABETS.size() - 1 - modifiedIndex;
                toModify = isupper(ch) ? toupper(ALPHABETS[modifiedIndex]) : ALPHABETS[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }

    std::string& Cipher::caesar() {

        for (char ch: getText()) {
            
            char toModify = isupper(ch) ? tolower(ch) : ch;
            size_t modifiedIndex {ALPHABETS.find(toModify)};

            if (modifiedIndex != std::string::npos) {
                
                modifiedIndex = (modifiedIndex + value) % ALPHABETS.size();
                toModify = isupper(ch) ? toupper(ALPHABETS[modifiedIndex]) : ALPHABETS[modifiedIndex];
            }

            result.push_back(toModify);
        }

        return result;
    }
}
