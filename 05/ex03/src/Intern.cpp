#include <iostream>

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"

Intern::Intern() {
    std::cout << "\x1b[33m""[Intern]: default constructor has called!""\x1b[0m" << std::endl;
}

Intern::Intern(Intern const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Intern]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Intern::~Intern() {
    std::cout << "\x1b[31m""[Intern]: destructor has called!""\x1b[0m" << std::endl;
}

Intern&	Intern::operator=(Intern const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[Intern]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Intern]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

AForm*	Intern::makeForm(std::string formName, std::string target) {
    if (formName == ShrubberyCreationForm::FORM_NAME)
        return (new ShrubberyCreationForm(target));
    else if (formName == RobotomyRequestForm::FORM_NAME)
        return (new RobotomyRequestForm(target));
    else if (formName == PresidentialPardonForm::FORM_NAME)
        return (new PresidentialPardonForm(target));
    else
        std::cout << "\x1b[31m""[Intern]: invalid form name!""\x1b[0m" << std::endl;
    return (NULL);
}
