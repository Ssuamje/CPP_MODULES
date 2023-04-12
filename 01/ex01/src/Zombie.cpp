/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:14:16 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:24:32 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie() {
	this->_name = "AnonymousZombie";
}

Zombie::Zombie(const std::string name) {
	this->_name = name;
	this->announce();
}

Zombie::~Zombie() {
	std::cout << this->_name << "[" << this->_number << "]" << " has been destroyed..." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << "[" << this->_number << "]: " << MUMBLE << std::endl;
}

void Zombie::setName(const std::string name) {
	this->_name = name;
}

void Zombie::setNumber(int number) {
	this->_number = number;
}