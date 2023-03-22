/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:32:19 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 10:39:02 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanB.hpp"

HumanB::HumanB() {
	
}

HumanB::~HumanB() {
	
}

HumanB::HumanB(std::string name) {
	this->_name = name;
}

void	HumanB::setWeapon(Weapon& weapon) {
	this->_weapon = weapon;
}

void	HumanB::attack() {
	if (this->_weapon.getType().empty() == false) {
		std::cout <<
		this->_name << " is wielding " << this->_weapon.getType() << std::endl;
	}
	else {
		std::cout <<
		this->_name << " is wielding fist" << std::endl;
	}
}
