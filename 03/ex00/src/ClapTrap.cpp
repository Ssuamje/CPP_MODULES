/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:28:56 by sanan             #+#    #+#             */
/*   Updated: 2023/04/09 16:47:27 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/ClapTrap.hpp"

ClapTrap::ClapTrap(): hitPoints(10), energyPoints(10) {
	std::cout << "\x1b[33m""[ClapTrap]: default constructor has called!""\x1b[0m" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &ref) {
	*this = ref;
	std::cout << "\x1b[35m""[ClapTrap]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

ClapTrap::ClapTrap(std::string name): hitPoints(10), energyPoints(10) {
	this->name = name;
	std::cout << "\x1b[35m""[ClapTrap]: name constructor has called!""\x1b[0m" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "\x1b[31m""[ClapTrap]: destructor has called!""\x1b[0m" << std::endl;
}

ClapTrap&	ClapTrap::operator=(ClapTrap const &ref) {
	if (this != &ref) {
		this->name = ref.name;
		this->hitPoints = ref.hitPoints;
		this->energyPoints = ref.energyPoints;
		this->attackDamage = ref.attackDamage;
		std::cout << "\x1b[34m""[ClapTrap]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[ClapTrap]: assign operator with same instance!""\x1b[0m" << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& ref) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[35m""[ClapTrap - " << this->name << "]: attacked " << ref << " with " << this->attackDamage << " damage!""\x1b[0m" << std::endl;
		this->energyPoints--;
	}
	else
		return ;
}

void	ClapTrap::takeDamage(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[35m""[ClapTrap - " << this->name << "]: got " << amount << " damage!""\x1b[0m" << std::endl;
		this->energyPoints--;
		this->hitPoints -= amount;
	}
	else
		return ;
}

void	ClapTrap::beRepaired(unsigned int amount) {
	if (isTrapActable() == true) {
		std::cout << "\x1b[35m""[ClapTrap - " << this->name << "]: repaired " << amount << " energy points!""\x1b[0m" << std::endl;
		this->energyPoints--;
		this->hitPoints += amount;
	}
	else
		return ;
}

bool	ClapTrap::isTrapActable() {
	return (this->energyPoints != 0
		&&	this->hitPoints != 0);
}
