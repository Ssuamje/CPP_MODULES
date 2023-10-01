#include "../include/Character.hpp"
#include "../include/MateriaSource.hpp"
#include "../include/Ice.hpp"
#include "../include/Cure.hpp"

void leaks() {
	system("leaks interface");
}

int main() {
	atexit(leaks);

	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	
	ICharacter* me = new Character("me");
	
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);

	ICharacter* bob = new Character("bob");

	me->use(0, *bob);
	me->use(1, *bob);

	delete bob;
	delete me;
	delete src;

	//**********************************
	// Test for unequip
	//**********************************
	// IMateriaSource* src = new MateriaSource();
	// src->learnMateria(new Ice());
	// src->learnMateria(new Cure());

	// ICharacter* me = new Character("me");

	// AMateria* tmp[2];
	// tmp[0] = src->createMateria("ice");
	// me->equip(tmp[0]);
	// tmp[1] = src->createMateria("cure");
	// me->equip(tmp[1]);

	// me->unequip(0);
	// me->unequip(1);

	// for (int i = 0; i < 2; i++)
	// 	delete tmp[i];
	// delete me;
	// delete src;

	return 0;
}