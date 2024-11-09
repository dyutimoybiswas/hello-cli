#include <iostream>
#include "../inc/inputhandler.hpp"

int main(int argc, char const *argv[]) {
    try {
        inputhandler::InputHandler handler(argc, argv);
        handler.processInput();
    } catch (std::invalid_argument& ie) {
        std::cerr << "Invalid argument: " << ie.what() << std::endl;
    } catch (std::logic_error& le) {
        std::cerr << "Input error: " << le.what() << std::endl;
    } catch (std::exception& e) {
        std::cerr << "Unknown error: " << e.what() << std::endl;
    }
    return 0;
}
