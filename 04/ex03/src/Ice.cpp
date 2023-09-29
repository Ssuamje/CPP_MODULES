#include <iostream>

#include "Ice.hpp"

Ice::Ice() {
	std::cout << "\x1b[33m""[Ice]: default constructor has called!""\x1b[0m" << std::endl;
	this->type = "ice";
}

Ice::Ice(const Ice& ref) {
	*this = ref;
	std::cout << "\x1b[35m""[Ice]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Ice::~Ice() {
	std::cout << "\x1b[31m""[Ice]: destructor has called!""\x1b[0m" << std::endl;
}

Ice&	Ice::operator=(const Ice& ref) {
	if (this != &ref) {
		//same as deep-copy
		std::cout << "\x1b[34m""[Ice]: copy operator has called!""\x1b[0m" << std::endl;
	}
	return (*this);
}

AMateria* Ice::clone() const {
	return (new Ice());
}

void Ice::use(ICharacter& target) {
	std::cout << "\x1b[32m""* shoots an ice bolt at " << target.getName() << " *""\x1b[0m" << std::endl;
}
