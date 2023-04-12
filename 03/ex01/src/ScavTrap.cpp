/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:28:56 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 09:45:20 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/ScavTrap.hpp"

ScavTrap::ScavTrap()
: name("missingno"), hitPoints(100), energyPoints(50), attackDamage(20), mode(NORMAL) {
	std::cout << "\x1b[33m""[ScavTrap]: default constructor has called!""\x1b[0m" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &ref) {
	*this = ref;
	std::cout << "\x1b[35m""[ScavTrap]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ScavTrap::ScavTrap(std::string name)
: hitPoints(100), energyPoints(50), attackDamage(20), mode(NORMAL) {
	this->name = name;
	std::cout << "\x1b[35m""[ScavTrap]: name constructor has called!""\x1b[0m" << std::endl;
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
	if (isTrapActable() == true) {
		std::cout << "\x1b[32m""[ScavTrap - " << this->name << "]: attacked " << ref << " with " << this->attackDamage << " damage!""\x1b[0m" << std::endl;
		this->energyPoints--;
	}
	else
		return ;
}

void	ScavTrap::takeDamage(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[31m""[ScavTrap - " << this->name << "]: got " << amount << " damage!""\x1b[0m" << std::endl;
		this->hitPoints -= amount;
	}
	else
		return ;
}

void	ScavTrap::beRepaired(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[33m""[ScavTrap - " << this->name << "]: repaired " << amount << " hit points!""\x1b[0m" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		return ;
}

bool	ScavTrap::isTrapActable() {
	if (this->energyPoints <= 0) {
		std::cout << "[ScavTrap - " << this->name << "]: is out of ENERGY!" << std::endl;
		return (false);
	}
	if (this->hitPoints <= 0) {
		std::cout << "[ScavTrap - " << this->name << "]: is out of HP!" << std::endl;
		return (false);
	}
	return (true);
}

void	ScavTrap::guardGate() {
	this->mode = GATE_KEEPER;
	std::cout << "[ScavTrap - " << this->name << "]: is now on gate keeper mode." << std::endl;
}