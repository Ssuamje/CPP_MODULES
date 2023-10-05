#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void leaks() {
    system("leaks intern");
}

int main() {
    Intern someRandomIntern;
    AForm* wrong;
    AForm* rrf;
    AForm* srf;
    AForm* ppf;

    wrong = someRandomIntern.makeForm("wrong", "sanan");
    std::cout << "wrong = " << wrong << std::endl;
    rrf = someRandomIntern.makeForm(RobotomyRequestForm::FORM_NAME, "eunbikim");
    std::cout << "rrf = " << dynamic_cast<RobotomyRequestForm&>(*rrf) << std::endl;
    srf = someRandomIntern.makeForm(ShrubberyCreationForm::FORM_NAME, "sichoi");
    std::cout << "srf = " << dynamic_cast<ShrubberyCreationForm&>(*srf) << std::endl;
    ppf = someRandomIntern.makeForm(PresidentialPardonForm::FORM_NAME, "dongglee");
    std::cout << "ppf = " << dynamic_cast<PresidentialPardonForm&>(*ppf) << std::endl;

    delete rrf;
    delete srf;
    delete ppf;
    atexit(leaks);
    return 0;
}