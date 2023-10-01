#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria {
	private:
		Ice(const Ice& ref);
		Ice&	operator=(const Ice& ref);

	public:
		Ice();
		~Ice();

		AMateria* clone() const;
		void use(ICharacter& target);
};

#endif
