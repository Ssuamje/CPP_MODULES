/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:14:16 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:22:25 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie::Zombie(std::string name) {
	this->_name = name;
	this->announce();
}

Zombie::~Zombie() {
	std::cout << this->_name << " has been destroyed..." << std::endl;
}

void Zombie::announce() {
	std::cout << this->_name << ": " << MUMBLE << std::endl;
}