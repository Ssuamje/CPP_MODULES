#include "RPN.hpp"

int main(int ac, char** av) {
    if (ac != 2) {
        std::cout << "Usage: ./RPN [Reverse Polish Notation Expression]" << std::endl;
        return (EXIT_FAILURE);
    }
    RPN rpn = RPN();
    
    rpn.doPostfixCalculate(av[1]);
    return EXIT_SUCCESS;
}