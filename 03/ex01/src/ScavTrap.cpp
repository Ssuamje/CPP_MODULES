/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:28:56 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 20:06:08 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap()
: ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->mode = NORMAL;
	std::cout << "\x1b[33m""[ScavTrap]: default constructor has called!""\x1b[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &ref): ClapTrap(ref) {
	*this = ref;
	std::cout << "\x1b[35m""[ScavTrap]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: ClapTrap(name) {
	std::cout << "\x1b[35m""[ScavTrap]: name constructor has called!""\x1b[0m" << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	this->mode = NORMAL;
}

ScavTrap::~ScavTrap() {
	std::cout << "\x1b[31m""[ScavTrap]: destructor has called!""\x1b[0m" << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap const &ref) {
	if (this != &ref) {
		this->name = ref.name;
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
		this->mode = ref.mode;
		std::cout << "\x1b[34m""[ScavTrap]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[ScavTrap]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& ref) {
	if (this->isActive()) {
		std::cout << "\x1b[32m""[ScavTrap - " << this->name << "]: attacked " << ref << " with " << this->attackDamage << " damage!""\x1b[0m" << std::endl;
		this->energyPoints--;
	}
	else {
		return ;
	}
}

void	ScavTrap::guardGate() {
	if (this->isActive()) {
		this->mode = GATE_KEEPER;
		std::cout << "[ScavTrap - " << this->name << "]: is now on gate keeper mode." << std::endl;
	} else {
		std::cout << "[ScavTrap - " << this->name << "]: I can't change mode!" << std::endl;
	}
}