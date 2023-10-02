#include <iostream>

#include "../include/ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "\x1b[33m""[ShrubberyCreationForm]: default constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref): AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[ShrubberyCreationForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
    std::cout << "\x1b[31m""[ShrubberyCreationForm]: destructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(ShrubberyCreationForm const &ref) {
    if (this != &ref) {
        this->target = ref.getTarget();
        this->isSigned = ref.getIsSigned();
        std::cout << "\x1b[34m""[ShrubberyCreationForm]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[ShrubberyCreationForm]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}
