#include <iostream>

#include "../include/Data.hpp"

Data::Data() {
    std::cout << "\x1b[33m""[Data]: default constructor has called!""\x1b[0m" << std::endl;
    this->data = "this is data!";
}

Data::Data(Data const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Data]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Data::~Data() {
    std::cout << "\x1b[31m""[Data]: destructor has called!""\x1b[0m" << std::endl;
}

Data&	Data::operator=(Data const &ref) {
    if (this != &ref) {
        this->data = ref.getData();
        std::cout << "\x1b[34m""[Data]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Data]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string Data::getData() const {
    return (this->data);
}
