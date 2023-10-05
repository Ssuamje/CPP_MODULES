#include <iostream>

#include "../include/Span.hpp"

Span::Span() {
    std::cout << "\x1b[33m""[Span]: default constructor has called!""\x1b[0m" << std::endl;
}

Span::Span(unsigned int n) : size(n) {
    std::cout << "\x1b[32m""[Span]: constructor has called!""\x1b[0m" << std::endl;
}

Span::Span(Span const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Span]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Span::~Span() {
    std::cout << "\x1b[31m""[Span]: destructor has called!""\x1b[0m" << std::endl;
}

Span&	Span::operator=(Span const &ref) {
    if (this != &ref) {
        size = ref.size;
        store = ref.store;
        std::cout << "\x1b[34m""[Span]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Span]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

void Span::addNumber(int num) {
    if (store.size() == size)
        throw FullSpanException();
    store.push_back(num);
}

int Span::shortestSpan() const {
    if (store.size() <= 1)
        throw NoSpanException();
    std::vector<int> tmp(store);

    std::sort(tmp.begin(), tmp.end());
    int min = tmp[1] - tmp[0];
    for (unsigned int i = 2; i < tmp.size(); i++)
        if (tmp[i] - tmp[i - 1] < min)
            min = tmp[i] - tmp[i - 1];
    return (min);
}

int Span::longestSpan() const {
    if (store.size() <= 1)
        throw NoSpanException();
    std::vector<int> tmp(store);

    std::sort(tmp.begin(), tmp.end());
    return (tmp[tmp.size() - 1] - tmp[0]);
}

const char *Span::NoSpanException::what() const throw() {
    return ("Span has no elements or only one element");
}

const char *Span::FullSpanException::what() const throw() {
    return ("Span has reached its maximum size");
}


