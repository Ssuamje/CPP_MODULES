#include <iostream>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	std::cout << "\x1b[33m""[MateriaSource]: default constructor has called!""\x1b[0m" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource& ref) {
	//compose deep-copy with your own class!
	std::cout << "\x1b[35m""[MateriaSource]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

MateriaSource::~MateriaSource() {
	std::cout << "\x1b[31m""[MateriaSource]: destructor has called!""\x1b[0m" << std::endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref) {
	if (this != &ref) {
		//same as deep-copy
		std::cout << "\x1b[34m""[MateriaSource]: copy operator has called!""\x1b[0m" << std::endl;
	}
	return (*this);
}

void MateriaSource::learnMateria(AMateria* m) {
	//implement
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	//implement
	return (NULL);
}