#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cout << "Usage: ./RPN [Reverse Polish Notation Expression]" << std::endl;
        return (EXIT_FAILURE);
    }
    RPN rpn = RPN();
    
    try {
        rpn.doPostfixCalculate(av[1]);
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
        return (EXIT_FAILURE);
    }
    return EXIT_SUCCESS;
}