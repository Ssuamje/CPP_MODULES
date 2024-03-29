#include <iostream>

#include "../include/RobotomyRequestForm.hpp"

static int times = 0;

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "\x1b[33m""[RobotomyRequestForm]: default constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &ref): AForm(ref.getName(), ref.getGradeToSign(), ref.getGradeToExecute()) {
    *this = ref;
    std::cout << "\x1b[35m""[RobotomyRequestForm]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45) {
    std::cout << "\x1b[33m""[RobotomyRequestForm]: constructor with target has called!""\x1b[0m" << std::endl;
    this->target = target;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "\x1b[31m""[RobotomyRequestForm]: destructor has called!""\x1b[0m" << std::endl;
}

std::string	RobotomyRequestForm::getTarget() const {
    return (this->target);
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(RobotomyRequestForm const &ref) {
    if (this != &ref) {
        this->target = ref.getTarget();
        this->isSigned = ref.getIsSigned();
        std::cout << "\x1b[34m""[RobotomyRequestForm]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[RobotomyRequestForm]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &ref) const {
    if (ref.getGrade() > this->gradeToExecute)
        throw AForm::GradeTooLowException();
    if (!this->isSigned)
        throw AForm::FormNotSignedException();
    if (times++ %2) {
        std::cout << "\x1b[32m""[RobotomyRequestForm]: (Drilling....) " << this->target << " has been robotomized successfully 50% of the time""\x1b[0m" << std::endl;
    } else {
        std::cout << "\x1b[31m""[RobotomyRequestForm]: " << this->target << " has been robotomized failure 50% of the time""\x1b[0m" << std::endl;
    }
}

