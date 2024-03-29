/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:22:42 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 20:05:12 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
	protected:
		std::string 	name;
		unsigned int	hitPoints;
		unsigned int	energyPoints;
		unsigned int	attackDamage;
		bool			isActive();

	public:
		ClapTrap();
		ClapTrap(const ClapTrap& ref);
		ClapTrap(std::string name);
		virtual ~ClapTrap();

		ClapTrap&	operator=(const ClapTrap& ref);

		virtual void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
