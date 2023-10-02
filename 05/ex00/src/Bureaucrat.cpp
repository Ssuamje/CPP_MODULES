#include <iostream>

#include "../include/Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {
    std::cout << "\x1b[33m""[Bureaucrat]: default constructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Bureaucrat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat::~Bureaucrat() {
    std::cout << "\x1b[31m""[Bureaucrat]: destructor has called!""\x1b[0m" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(Bureaucrat const &ref) {
    if (this != &ref) {
        this->grade = ref.grade;
        std::cout << "\x1b[34m""[Bureaucrat]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Bureaucrat]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

const std::string& Bureaucrat::getName() const {
    return (this->name);
}

int Bureaucrat::getGrade() const {
    return (this->grade);
}

void Bureaucrat::incrementGrade() {
    if (this->grade - 1 < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}

void Bureaucrat::decrementGrade() {
    if (this->grade + 1 > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

Bureaucrat::Bureaucrat(const std::string& name, int grade): name(name) {
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is too high!");
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is too low!");
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref) {
    os << "\x1b[32m""[Bureaucrat]: " << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".""\x1b[0m";
    return (os);
}