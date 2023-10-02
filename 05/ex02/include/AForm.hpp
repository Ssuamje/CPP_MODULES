#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;
class AForm {

    private:
        AForm();
        const std::string   name;
        bool                isSigned;
        const int           gradeToSign;
        const int           gradeToExecute;

    protected:
        AForm(const AForm& ref);
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);

    public:
        virtual ~AForm();

        AForm&	operator=(const AForm& ref);

        const std::string&  getName() const;
        bool                getIsSigned() const;
        int                 getGradeToSign() const;
        int                 getGradeToExecute() const;
        void                beSigned(const class Bureaucrat& ref);
        virtual void        execute(const class Bureaucrat& executor) const = 0;

        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        class FormNotSignedException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

std::ostream&   operator<<(std::ostream& os, const AForm& ref);

#endif
