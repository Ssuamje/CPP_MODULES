/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:28:56 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 15:43:37 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/FragTrap.hpp"

FragTrap::FragTrap()
: ClapTrap() {
	std::cout << "\x1b[33m""[FragTrap]: default constructor has called!""\x1b[0m" << std::endl;
}

FragTrap::FragTrap(FragTrap const &ref) {
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

void	FragTrap::highFivesGuys() {
	if (this->isTrapActable())
		std::cout << "[FragTrap - " << this->name << "]: is looking for +highfive+ mate!" << std::endl;
}