#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm: public AForm {
    private:
        std::string  target;

        RobotomyRequestForm();

    public:
        static const std::string FORM_NAME;
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& ref);
        ~RobotomyRequestForm();

        RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

        void        execute(const Bureaucrat& executor) const;
        std::string getTarget() const;
};

std::ostream&	operator<<(std::ostream& os, const RobotomyRequestForm& ref);

#endif
