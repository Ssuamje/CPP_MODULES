#include <iostream>

#include "../include/RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() {
    std::cout << "\x1b[33m""[RobotomyRequestForm]: default constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[RobotomyRequestForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\x1b[31m""[RobotomyRequestForm]: destructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[RobotomyRequestForm]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[RobotomyRequestForm]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}
