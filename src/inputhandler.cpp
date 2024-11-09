#include <memory>
#include <stdexcept>
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
            display::Display::output("Hello, CLI!");

        // Output help text.
        else if (args.front() == "--help" || args.front() == "-h")
            display::Display::help();
        
        else {
            std::string lastArgument;
            std::string operation;
            std::string text;
            std::unique_ptr<operations::Operation> op;
            size_t i {0};
            size_t value {0};
            bool isTextFlagProvided {false};

            for (; i < args.size(); i += 2) {
                
                if (args[i] == "-t" || args[i] == "--text") {

                    if (lastArgument.empty())
                        throw std::logic_error("Please specify type of operation before providing text.");                    
                    
                    else {
                        isTextFlagProvided = true;
                        break;
                    }
                }

                if (args[i] == "-c" || args[i] == "--casing") {

                    lastArgument = "--casing";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    operation = args[i + 1];
                    validateValue(lastArgument, operation);

                } else if (args[i] == "-p" || args[i] == "--pattern") {

                    lastArgument = "--pattern";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    operation = args[i + 1];
                    validateValue(lastArgument, operation);

                    if (operation == "wave")
                        value = 1;

                } else if (args[i] == "-v" || args[i] == "--value") {

                    lastArgument = "--value";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    for (char ch: args[i + 1])
                        if (ch != '-' && ch != '+' && !isdigit(ch))
                            throw std::invalid_argument("Value must be numeric.");

                    if (std::stoi(args[i + 1]) < 0)
                        throw std::invalid_argument("Value cannot be negative.");
                    
                    value = std::stoul(args[i + 1]);

                    validateValue(lastArgument);

                } else if (args[i] == "-C" || args[i] == "--cipher") {

                    lastArgument = "--cipher";

                    if (i + 1 == args.size())
                        throw std::logic_error("Value for specified operation cannot be empty.");

                    operation = args[i + 1];
                    validateValue(lastArgument, operation);

                    if (operation == "caesar")
                        value = 3;

                } else
                    throw std::logic_error("Please specify a valid operation.");
            }

            if (isTextFlagProvided) {

                for (; i < args.size() - 1; ++i) {
                
                    text.append(args[i + 1]);
                    text.append(" ");
                }

                if (text.empty())
                    throw std::logic_error("Text cannot be empty.");
            } else
                text = "Hello, CLI!";

            if (lastArgument == "--casing")
                op = std::make_unique<operations::Casing>(operation, text);
            
            else if (lastArgument == "--pattern")
                op = std::make_unique<operations::Pattern>(operation, value, text);

            else if (lastArgument == "--cipher")
                op = std::make_unique<operations::Cipher>(operation, value, text);

            display::Display::output(op.get()->operate());
        }
    }

    void InputHandler::validateValue(const std::string& op, const std::string& choice) {

        if (ops.count(op))
            throw std::logic_error("Operation(s) cannot be repeated.");

        ops.insert(op);

        if (op != "--value") {
            std::vector<std::string> validValues = validMappings.find(op)->second;

            if (!std::any_of(validValues.cbegin(), validValues.cend(), [choice](const std::string& value) -> bool { return value == choice; }))
                throw std::invalid_argument("Value entered for the given operation is incorrect.");        
        }
    }
}
