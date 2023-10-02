#include "Bureaucrat.hpp"

void leaks() {
    system("leaks bureaucrat");
}

int main() {

    //정상 생성
    Bureaucrat* normal = new Bureaucrat("normal", 1);
    std::cout << *normal << std::endl;
    delete normal;

    //등수가 너무 높음
    try {
        Bureaucrat* tooHigh = new Bureaucrat("tooHigh", 0);
        std::cout << *tooHigh << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    //등수가 너무 낮음
    try {
        Bureaucrat* tooLow = new Bureaucrat("tooLow", 151);
        std::cout << *tooLow << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    // 등수가 너무 낮기 직전 
    Bureaucrat* almostLow = new Bureaucrat("almostLow", 150);
    try {
        almostLow->decrementGrade();
        std::cout << *almostLow << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    delete almostLow;

    // 등수가 너무 높기 직전
    Bureaucrat* almostHigh = new Bureaucrat("almostHigh", 1);
    try {
        almostHigh->incrementGrade();
        std::cout << *almostHigh << std::endl;
    } catch (std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    delete almostHigh;

    atexit(leaks);
    return 0;
}