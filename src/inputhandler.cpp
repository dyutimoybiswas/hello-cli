#include <memory>
#include <stdexcept>
#include <algorithm>
#include "inputhandler.hpp"
#include "display.hpp"
#include "operations.hpp"

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
            std::string lastArgument;
            std::string operation;
            std::string text;
            std::unique_ptr<operations::Operation> op;
            size_t i;

            for (i = 0; i < args.size() - 1; i += 2) {
                
                if (args[i] == "-t" || args[i] == "--text") {

                    if (lastArgument.empty())
                        throw std::logic_error("Please specify type of operation before providing text.");                    
                    else
                        break;
                }

                if (args[i] == "-c" || args[i] == "--casing") {

                    lastArgument = "--casing";
                    operation = args[i + 1];
                    validateValue(lastArgument, operation);

                } else if (args[i] == "-p" || args[i] == "--pattern") {
                    // TODO:                    
                } else
                    throw std::logic_error("Please specify a valid operation.");
            }

            for (; i < args.size() - 1; ++i) {
                
                text.append(args[i + 1]);
                text.append(" ");
            }

            if (text.empty())
                throw std::logic_error("Text cannot be empty.");

            if (lastArgument == "--casing")
                op = std::make_unique<operations::Casing>(operation, text);

            display::Display::output(op.get()->operate());
        }
    }

    void InputHandler::validateValue(const std::string& op, const std::string& choice) {

        std::vector<std::string> validValues = validMappings.find(op)->second;

        if (!std::any_of(validValues.cbegin(), validValues.cend(), [choice](const std::string& value) -> bool { return value == choice; }))
            throw std::logic_error("Invalid value entered for the given operation.");
    }
}
