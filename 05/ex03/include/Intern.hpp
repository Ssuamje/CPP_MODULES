#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern {
    private:

    public:
        Intern();
        Intern(const Intern& ref);
        ~Intern();

        Intern&	operator=(const Intern& ref);

        AForm*	makeForm(std::string formName, std::string target);
};

#endif
