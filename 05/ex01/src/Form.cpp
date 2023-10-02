#include <iostream>

#include "../include/Form.hpp"

Form::Form(): name("default"), gradeToSign(150), gradeToExecute(150) {
    this->isSigned = false;
    std::cout << "\x1b[33m""[Form]: default constructor has called!""\x1b[0m" << std::endl;
}

Form::Form(Form const &ref): name(ref.getName()), gradeToSign(ref.getGradeToSign()), gradeToExecute(ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[Form]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Form::~Form() {
    std::cout << "\x1b[31m""[Form]: destructor has called!""\x1b[0m" << std::endl;
}

Form&	Form::operator=(Form const &ref) {
    if (this != &ref) {
        this->isSigned = ref.getIsSigned();
        std::cout << "\x1b[34m""[Form]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Form]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

const std::string& Form::getName() const {
    return (this->name);
}

bool Form::getIsSigned() const {
    return (this->isSigned);
}

int Form::getGradeToSign() const {
    return (this->gradeToSign);
}

int Form::getGradeToExecute() const {
    return (this->gradeToExecute);
}

void Form::beSigned(Bureaucrat const &ref) {
    if (ref.getGrade() > this->gradeToSign)
        throw Form::GradeTooLowException();
    this->isSigned = true;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute): name(name), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute) {
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw Form::GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw Form::GradeTooLowException();
    this->isSigned = false;
}

const char* Form::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* Form::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

std::ostream&   operator<<(std::ostream& os, const Form& ref) {
    os << "\x1b[32m""name: " << ref.getName()
    << " isSigned: " << ref.getIsSigned()
    << " gradeToSign: " << ref.getGradeToSign()
    << " gradeToExecute: " << ref.getGradeToExecute();
    return (os);
}