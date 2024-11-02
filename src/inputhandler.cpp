#include "inputhandler.hpp"
#include "display.hpp"

namespace inputhandler {

    InputHandler::InputHandler(int argc, const char* argv[]) {

        for (int i = 1; i < argc; ++i)
            args.push_back(argv[i]);
    }

    void InputHandler::processInput() {

        // Output default.
        if (args.empty())
            display::Display::output("Hello, CLI");

        // Output help text.
        else if (args.front() == "--help" || args.front() == "-h")
            display::Display::help();
        
        else {

        }
    }
}
