/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:32:19 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:46:11 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB(const std::string name)
	: _weapon(NULL) {
	this->_name = name;
}

HumanB::~HumanB() {
	
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = &weapon;
}

void	HumanB::attack() {
	if (this->_weapon != NULL) {
		std::cout <<
		this->_name << " is wielding " << this->_weapon->getType() << std::endl;
	}
	else {
		std::cout <<
		this->_name << " is wielding fist" << std::endl;
	}
}
