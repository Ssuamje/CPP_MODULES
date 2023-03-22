/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:45:20 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 22:13:23 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::~Weapon() {
	
}

Weapon::Weapon(std::string type) {
	this->_type = type;
}

std::string Weapon::getType() {
	return (this->_type);
}

void	Weapon::setType(std::string newType) {
	this->_type = newType;
}