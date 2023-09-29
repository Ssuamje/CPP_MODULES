/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:22:58 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 20:00:44 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ScavTrap.hpp"

int main() {
	ScavTrap	sanan("SANAN");
	ScavTrap	yooh("YOOH");
	std::string target = "TARGET";

	sanan.attack(target);
	sanan.attack(target);
	sanan.attack(target);
	sanan.attack(target);
	sanan.attack(target);
	sanan.takeDamage(5);
	sanan.attack(target);
	sanan.beRepaired(10);
	sanan.attack(target);
	sanan.attack(target);
	sanan.attack(target);
	sanan.attack(target);
	sanan.beRepaired(1);

	yooh.takeDamage(100);
	yooh.attack(target);
	yooh.beRepaired(10);

	return 0;
}