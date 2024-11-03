#include "operations.hpp"

namespace operations {

    // TODO: based on option, perform operations.

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

        return result;
    }

    std::string& Cipher::operate() noexcept {

        return result;
    }
}
