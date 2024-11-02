#ifndef INPUTHANDLER_HPP
#define INPUTHANDLER_HPP

#include <map>
#include <vector>
#include <string>
#include <utility>
#include <stdexcept>

namespace inputhandler {

    class InputHandler {

        public:

            InputHandler(int argc, const char* argv[]);
            void processInput();

        private:

            const std::map<const char*, std::vector<const char*>> validMappings  = {
                std::make_pair("--casing", std::vector({"lowercase", "uppercase", "togglecase", "spongebobcase"})),
                std::make_pair("--pattern", std::vector({"reverse", "spacing", "wave"})),
                std::make_pair("--spacing", std::vector({"value"})),
                std::make_pair("--wave", std::vector({"value"}))
            };
            std::vector<std::string> args;
    };
}

#endif
