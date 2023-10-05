#include <iostream>

#include "../include/Base.hpp"
#include "../include/A.hpp"
#include "../include/B.hpp"
#include "../include/C.hpp"

/**
 * dynamic_cast는 C++에서 다형성을 지원하기 위한 연산자 중 하나로, 주로 클래스의 상속 계층 구조에서 사용됩니다. 
 * dynamic_cast는 런타임에 타입 안전성을 검사하며, 안전하지 않은 형변환을 방지하기 위해 사용됩니다.

dynamic_cast의 동작은 다음과 같습니다:

객체 포인터를 다른 클래스 타입의 포인터로 캐스팅하려고 할 때 사용됩니다.
이 때, 기본 클래스와 파생 클래스 사이의 상속 관계가 있어야 합니다.
dynamic_cast는 런타임에 객체의 실제 타입을 확인하고, 만약 타입이 호환되지 않는 경우 NULL 포인터를 반환합니다. 이 때, 예외를 던지지 않습니다.
*/
Base::~Base() {
    std::cout << "\x1b[31m""[Base]: destructor has called!""\x1b[0m" << std::endl;
}

Base*	Base::generate(void) {
    std::srand(std::time(NULL));
    int random = std::rand() % 3;
    if (random == 0) {
        std::cout << "\x1b[32m""[generate]: A has generated!""\x1b[0m" << std::endl;
        return (new A());
    }
    else if (random == 1) {
        std::cout << "\x1b[32m""[generate]: B has generated!""\x1b[0m" << std::endl;
        return (new B());
    }
    else {
        std::cout << "\x1b[32m""[generate]: C has generated!""\x1b[0m" << std::endl;
        return (new C());
    }
}

void	Base::identify(Base *p) {
    if (dynamic_cast<A*>(p) != NULL)
        std::cout << "\x1b[32m""[identify_from_pointer]: A has identified!""\x1b[0m" << std::endl;
    else if (dynamic_cast<B*>(p) != NULL)
        std::cout << "\x1b[32m""[identify_from_pointer]: B has identified!""\x1b[0m" << std::endl;
    else if (dynamic_cast<C*>(p) != NULL)
        std::cout << "\x1b[32m""[identify_from_pointer]: C has identified!""\x1b[0m" << std::endl;
    else
        std::cout << "\x1b[32m""[identify_from_pointer]: unknown class has identified!""\x1b[0m" << std::endl;
}

void	Base::identify(Base &p) {
    if (dynamic_cast<A*>(&p) != NULL)
        std::cout << "\x1b[32m""[identify_from_reference]: A has identified!""\x1b[0m" << std::endl;
    else if (dynamic_cast<B*>(&p) != NULL)
        std::cout << "\x1b[32m""[identify_from_reference]: B has identified!""\x1b[0m" << std::endl;
    else if (dynamic_cast<C*>(&p) != NULL)
        std::cout << "\x1b[32m""[identify_from_reference]: C has identified!""\x1b[0m" << std::endl;
    else
        std::cout << "\x1b[32m""[identify_from_reference]: unknown class has identified!""\x1b[0m" << std::endl;
}
