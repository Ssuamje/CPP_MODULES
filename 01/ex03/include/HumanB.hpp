/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:40:43 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 22:16:36 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanB{
	private:
	std::string	_name;
	Weapon		*_weapon;
	
	public:
	HumanB(std::string name);
	~HumanB();
	void	setWeapon(Weapon& weapon);
	void	attack();
};

#endif