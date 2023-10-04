#include <iostream>

#include "../include/Serializer.hpp"

Serializer::Serializer() {
    std::cout << "\x1b[33m""[Serializer]: default constructor has called!""\x1b[0m" << std::endl;
}

Serializer::Serializer(Serializer const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Serializer]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Serializer::~Serializer() {
    std::cout << "\x1b[31m""[Serializer]: destructor has called!""\x1b[0m" << std::endl;
}

Serializer&	Serializer::operator=(Serializer const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[Serializer]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Serializer]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

uintptr_t	Serializer::serialize(Data* ptr) {
    return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		Serializer::deserialize(uintptr_t raw) {
    return (reinterpret_cast<Data*>(raw));
}
