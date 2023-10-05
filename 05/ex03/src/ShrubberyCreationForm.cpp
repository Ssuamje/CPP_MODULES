#include <iostream>
#include <fstream>

#include "../include/ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::FORM_NAME = "ShrubberyCreationForm";

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "\x1b[33m""[ShrubberyCreationForm]: default constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &ref): AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[ShrubberyCreationForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target): AForm("ShrubberyCreationForm", 145, 137) {
    std::cout << "\x1b[33m""[ShrubberyCreationForm]: constructor with target has called!""\x1b[0m" << std::endl;
    this->target = target;
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

std::string ShrubberyCreationForm::getTarget() const {
    return (this->target);
}

const char* ShrubberyCreationForm::FileOpenException::what() const throw() {
    return ("Can't open file!");
}

void    ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (executor.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    std::ofstream ofs;
    ofs.open(this->target + "_shrubbery");
	if (ofs.is_open() == false)
		throw ShrubberyCreationForm::FileOpenException();
	ofs << 
    "               ,@@@@@@@,\n\
       ,,,.   ,@@@@@@/@@,  .oo8888o.\n\
    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n\
   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n\
   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n\
   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n\
   `&%\\ ` /%&'    |.|        \\ '|8'\n\
       |o|        | |         | |\n\
       |.|        | |         | |\n\
    \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_\n";
	ofs.close();
}

std::ostream&	operator<<(std::ostream& os, const ShrubberyCreationForm& ref) {
    os << ref.getName() << " has grade to sign " << ref.getGradeToSign() << ", grade to execute " << ref.getGradeToExecute() << ", and target " << ref.getTarget();
    return (os);
}
