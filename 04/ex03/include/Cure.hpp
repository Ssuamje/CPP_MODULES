#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria {
	private:
		Cure(const Cure& ref);
		Cure&	operator=(const Cure& ref);

	public:
		Cure();
		~Cure();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
