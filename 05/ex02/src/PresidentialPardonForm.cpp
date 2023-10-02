#include <iostream>

#include "../include/PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "\x1b[33m""[PresidentialPardonForm]: default constructor has called!""\x1b[0m" << std::endl;
    this->target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &ref): AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[PresidentialPardonForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target): AForm("PresidentialPardonForm", 25, 5) {
    std::cout << "\x1b[33m""[PresidentialPardonForm]: constructor with target has called!""\x1b[0m" << std::endl;
    this->target = target;
}

PresidentialPardonForm::~PresidentialPardonForm() {
    std::cout << "\x1b[31m""[PresidentialPardonForm]: destructor has called!""\x1b[0m" << std::endl;
}


PresidentialPardonForm&	PresidentialPardonForm::operator=(PresidentialPardonForm const &ref) {
    if (this != &ref) {
        this->target = ref.getTarget();
        this->isSigned = ref.getIsSigned();
        std::cout << "\x1b[34m""[PresidentialPardonForm]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[PresidentialPardonForm]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string	PresidentialPardonForm::getTarget() const {
    return (this->target);
}
