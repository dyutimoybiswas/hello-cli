#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <stdexcept>

namespace inputhandler {

    class InputHandler {

        public:

            InputHandler(int argc, const char* argv[]);
            void processInput();

        private:

            const std::unordered_map<std::string, std::vector<std::string>> validMappings  = {
                {"--casing", {"lowercase", "uppercase", "togglecase", "spongebobcase"}},
                {"--pattern", {"reverse", "spacing", "wave"}},
                {"--cipher", {"atbash", "caesar"}}
            };
            std::vector<std::string> args;
            std::unordered_set<std::string> ops;
            void validateValue(const std::string&, const std::string& = "");
    };
}

#endif
