#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        std::string   target;

        PresidentialPardonForm();

    public:
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& ref);
        ~PresidentialPardonForm();

        PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

        void        execute(const Bureaucrat& executor) const;
        std::string getTarget() const;

        class FileNotOpenedException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

};

#endif
