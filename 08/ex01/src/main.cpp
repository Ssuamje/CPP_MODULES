#include "Span.hpp"

void leaks() {
    system("leaks span");
}

int main() {
    /* 깊은 복사가 잘 이뤄지는지에 대한 assignment 테스트 */
    // Span sp = Span(4);
    // Span sp2 = Span(4);
    // sp.addNumber(5);
    // sp.addNumber(3);
    // sp.addNumber(4);
    // sp2 = sp;
    // sp2.addNumber(9);
    // sp.addNumber(11);
    // std::cout << sp.shortestSpan() << std::endl;
    // std::cout << sp2.shortestSpan() << std::endl;
    // std::cout << sp.longestSpan() << std::endl;
    // std::cout << sp2.longestSpan() << std::endl;
    /* 예제 테스트 */
    Span test = Span(5);

    test.addNumber(6);
    test.addNumber(3);
    test.addNumber(17);
    test.addNumber(9);
    test.addNumber(11);

    std::cout << test.shortestSpan() << std::endl; // 2
    std::cout << test.longestSpan() << std::endl; // 14

    /* 작동 테스트 */
    Span sp = Span(10000);
    for (int i = 0; i < 10000; i++)
        sp.addNumber(i);
    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    /* 예외 테스트 */
    Span sp2 = Span(4);
    try {
        sp2.shortestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        sp2.longestSpan();
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    try {
        for (int i = 0; i < 5; i++)
            sp2.addNumber(i);
    }
    catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }
    // atexit(leaks);
    return (0);
}