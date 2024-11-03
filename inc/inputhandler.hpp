#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <map>
#include <vector>
#include <string>
#include <stdexcept>

namespace inputhandler {

    class InputHandler {

        public:

            InputHandler(int argc, const char* argv[]);
            void processInput();

        private:

            const std::map<std::string, std::vector<std::string>> validMappings  = {
                {"--casing", {"lowercase", "uppercase", "togglecase", "spongebobcase"}},
                {"--pattern", {"reverse", "spacing", "wave"}},
                {"--spacing", {"value"}},
                {"--wave", {"value"}}
            };
            std::vector<std::string> args;
            void validateValue(const std::string&, const std::string&);
    };
}

#endif
