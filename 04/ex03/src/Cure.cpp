#include <iostream>

#include "Cure.hpp"

Cure::Cure() {
	std::cout << "\x1b[33m""[Cure]: default constructor has called!""\x1b[0m" << std::endl;
	this->type = "cure";
}

Cure::Cure(const Cure& ref) {
	*this = ref;
	std::cout << "\x1b[35m""[Cure]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cure::~Cure() {
	std::cout << "\x1b[31m""[Cure]: destructor has called!""\x1b[0m" << std::endl;
}

Cure&	Cure::operator=(const Cure& ref) {
	if (this != &ref) {
		//same as deep-copy
		std::cout << "\x1b[34m""[Cure]: copy operator has called!""\x1b[0m" << std::endl;
	}
	return (*this);
}

AMateria* Cure::clone() const {
	return (new Cure());
}

void Cure::use(ICharacter& target) {
	std::cout << "\x1b[32m""* heals " << target.getName() << "'s wounds *""\x1b[0m" << std::endl;
}
