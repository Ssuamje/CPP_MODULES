/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:35:30 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 09:43:53 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

enum	scavTrapModes {
	NORMAL,
	GATE_KEEPER,
};

class ScavTrap : public ClapTrap {
	private:
		std::string		name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		int				mode;

	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& ref);
		~ScavTrap();

		ScavTrap&	operator=(const ScavTrap& ref);
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		bool	isTrapActable();
		void	guardGate();
};

#endif
