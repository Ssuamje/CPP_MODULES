/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 10:18:29 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:44:34 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HumanA.hpp"

HumanA::HumanA(const std::string name, Weapon& weapon) 
	: _weapon(weapon) {
	this->_name = name;
}

HumanA::~HumanA() {
	
}

void	HumanA::attack() {
	if (this->_weapon.getType().empty() == false) {
		std::cout <<
		this->_name << " is wielding " << this->_weapon.getType() << std::endl;
	}
	else {
		std::cout <<
		this->_name << " is wielding fist" << std::endl;
	}
}