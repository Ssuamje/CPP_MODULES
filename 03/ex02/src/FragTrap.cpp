/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:28:56 by sanan             #+#    #+#             */
/*   Updated: 2023/09/28 22:45:15 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap() {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "\x1b[33m""[FragTrap]: default constructor has called!""\x1b[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref): ClapTrap(ref) {
	*this = ref;
	std::cout << "\x1b[35m""[FragTrap]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

FragTrap::FragTrap(std::string name)
: ClapTrap(name) {
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << "\x1b[35m""[FragTrap]: name constructor has called!""\x1b[0m" << std::endl;
}

FragTrap::~FragTrap() {
	std::cout << "\x1b[31m""[FragTrap]: destructor has called!""\x1b[0m" << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap const &ref) {
	if (this != &ref) {
		this->name = ref.name;
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
		std::cout << "\x1b[34m""[FragTrap]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[FragTrap]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	FragTrap::attack(const std::string& ref) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[32m""[FragTrap - " << this->name << "]: attacked " << ref << " with " << this->attackDamage << " damage!""\x1b[0m" << std::endl;
		this->energyPoints--;
	}
	else
		return ;
}

void	FragTrap::takeDamage(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[31m""[FragTrap - " << this->name << "]: got " << amount << " damage!""\x1b[0m" << std::endl;
		this->hitPoints -= amount;
	}
	else
		return ;
}

void	FragTrap::beRepaired(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[33m""[FragTrap - " << this->name << "]: repaired " << amount << " hit points!""\x1b[0m" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		return ;
}

bool	FragTrap::isTrapActable() {
	if (this->hitPoints <= 0) {
		std::cout << "[FragTrap - " << this->name << "]: is out of HP!" << std::endl;
		return (false);
	}
	if (this->energyPoints <= 0) {
		std::cout << "[FragTrap - " << this->name << "]: is out of ENERGY!" << std::endl;
		return (false);
	}
	return (true);
}

void	FragTrap::highFivesGuys() {
	std::cout << "[FragTrap - " << this->name << "]: is looking for +highfive+ mate!" << std::endl;
}