#include <iostream>

#include "../include/AForm.hpp"

AForm::AForm(): name("default"), gradeToSign(150), gradeToExecute(150) {
    this->isSigned = false;
    std::cout << "\x1b[33m""[AForm]: default constructor has called!""\x1b[0m" << std::endl;
}

AForm::AForm(AForm const &ref): name(ref.getName()), gradeToSign(ref.getGradeToSign()), gradeToExecute(ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[AForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

AForm::~AForm() {
    std::cout << "\x1b[31m""[AForm]: destructor has called!""\x1b[0m" << std::endl;
}

AForm&	AForm::operator=(AForm const &ref) {
    if (this != &ref) {
        this->isSigned = ref.getIsSigned();
        std::cout << "\x1b[34m""[AForm]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[AForm]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

const std::string& AForm::getName() const {
    return (this->name);
}

bool AForm::getIsSigned() const {
    return (this->isSigned);
}

int AForm::getGradeToSign() const {
    return (this->gradeToSign);
}

int AForm::getGradeToExecute() const {
    return (this->gradeToExecute);
}

void AForm::beSigned(Bureaucrat const &ref) {
    if (ref.getGrade() > this->gradeToSign)
        throw AForm::GradeTooLowException();
    this->isSigned = true;
}

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw AForm::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw AForm::GradeTooLowException();
    this->isSigned = false;
}

const char* AForm::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* AForm::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return ("Form is not signed!");
}

std::ostream&   operator<<(std::ostream& os, const AForm& ref) {
    os << "\x1b[32m""name: " << ref.getName()
    << " isSigned: " << ref.getIsSigned()
    << " gradeToSign: " << ref.getGradeToSign()
    << " gradeToExecute: " << ref.getGradeToExecute();
    return (os);
}