#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource: public IMateriaSource {
	private:
		static const int CAPACITY = 4;
		AMateria* store[CAPACITY];
		MateriaSource(const MateriaSource& ref);
		MateriaSource&	operator=(const MateriaSource& ref);

	public:
		MateriaSource();
		~MateriaSource();

		void learnMateria(AMateria*);
		AMateria* createMateria(std::string const & type);
};

#endif
