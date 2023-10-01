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
	for (int i = 0; i < MateriaSource::CAPACITY; i++) {
		if (this->store[i] != NULL) {
			delete this->store[i];
			this->store[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref) {
	if (this != &ref) {
		std::cout << "\x1b[34m""[MateriaSource]: copy operator has called!""\x1b[0m" << std::endl;
		for (int i = 0; i < MateriaSource::CAPACITY; i++) {
			if (this->store[i] != NULL) {
				delete this->store[i];
				this->store[i] = NULL;
			}
			this->store[i] = ref.store[i]->clone();
		}
	}
	else
		std::cout << "\x1b[34m""[MateriaSource]: copy operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < MateriaSource::CAPACITY; i++) {
        if (this->store[i] == NULL) {
            this->store[i] = m;
            break ;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	if (type.empty())
		return (NULL);
	for (int i = 0; i < MateriaSource::CAPACITY; i++) {
		if (this->store[i] != NULL && this->store[i]->getType() == type) {
			return (this->store[i]->clone());
		}
	}
	return (NULL);
}