#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
    Bureaucrat sanan("sanan", 1);
    Bureaucrat babo("babo", 150);
    ShrubberyCreationForm scFormYooh("yooh");

    std::cout << std::endl;

    std::cout << sanan << std::endl;
    std::cout << babo << std::endl;
    std::cout << scFormYooh << std::endl;

    std::cout << std::endl;

    babo.signForm(scFormYooh);
    sanan.signForm(scFormYooh);
    babo.executeForm(scFormYooh);
    sanan.executeForm(scFormYooh);

    std::cout << std::endl;
    std::cout << "*******************************************" << std::endl;

    RobotomyRequestForm rrFormJpark("jpark2");
    
    std::cout << std::endl;

    std::cout << rrFormJpark << std::endl;
    
    std::cout << std::endl;
    
    babo.signForm(rrFormJpark);
    sanan.signForm(rrFormJpark);
    babo.executeForm(rrFormJpark);
    sanan.executeForm(rrFormJpark);
    sanan.executeForm(rrFormJpark);
    sanan.executeForm(rrFormJpark);
    sanan.executeForm(rrFormJpark);

    std::cout << std::endl;
    std::cout << "*******************************************" << std::endl;

    PresidentialPardonForm ppFormJbok("jbok");

    std::cout << std::endl;

    std::cout << ppFormJbok << std::endl;

    std::cout << std::endl;
    
    babo.signForm(ppFormJbok);
    sanan.signForm(ppFormJbok);
    babo.executeForm(ppFormJbok);
    sanan.executeForm(ppFormJbok);

    std::cout << std::endl;
    std::cout << "********************END********************" << std::endl;

    return 0;
}