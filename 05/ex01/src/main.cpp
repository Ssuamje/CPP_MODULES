#include "Form.hpp"

int main() {

    // 임계값을 넘는 Form을 생성하는 경우
    try {
        Form    tooHigh("tooHigh", 0, 0);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    try {
        Form    tooLow("tooLow", 151, 151);
    }
    catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat  sanan("sanan", 1);
    Bureaucrat  babo("babo", 150);
    Form        onlyFirst("onlyFirst", 1, 1);
    Form        defaultForm;

    std::cout << std::endl;

    std::cout << sanan << std::endl;
    std::cout << babo << std::endl;
    std::cout << defaultForm << std::endl;
    std::cout << onlyFirst << std::endl;


    std::cout << std::endl;

    sanan.signForm(defaultForm);
    babo.signForm(defaultForm);
    sanan.signForm(onlyFirst);
    babo.signForm(onlyFirst);

    std::cout << std::endl;
    return 0;
}