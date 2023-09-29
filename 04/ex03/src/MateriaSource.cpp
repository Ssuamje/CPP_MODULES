#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "\x1b[33m""[MateriaSource]: default constructor has called!""\x1b[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& ref) {
	*this = ref;
	std::cout << "\x1b[35m""[MateriaSource]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "\x1b[31m""[MateriaSource]: destructor has called!""\x1b[0m" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref) {
	std::cout << "\x1b[34m""[MateriaSource]: copy operator has called!""\x1b[0m" << std::endl;
	if (this != &ref) {
		//Nothing
	}
	throw std::runtime_error("Factory cannot be assigned to another!\n");
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::CAPACITY; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	//implement
	return (NULL);
}