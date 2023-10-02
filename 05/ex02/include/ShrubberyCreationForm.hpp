#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    private:
        std::string  target;

        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& ref);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm&	operator=(const ShrubberyCreationForm& ref);

        void        execute(const Bureaucrat& executor) const;
        std::string getTarget() const;

        class FileOpenException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
};

#endif
