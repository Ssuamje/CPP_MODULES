/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:45:20 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:42:05 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Weapon.hpp"

Weapon::Weapon() {
	
}

Weapon::~Weapon() {
	
}

Weapon::Weapon(const std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType() {
	return (this->_type);
}

void	Weapon::setType(const std::string newType) {
	this->_type = newType;
}