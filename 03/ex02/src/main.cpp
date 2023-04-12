/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:22:58 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 10:31:47 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FragTrap.hpp"

int main() {
	FragTrap	sanan("SANAN");
	FragTrap	yooh("YOOH");
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
	sanan.highFivesGuys();

	yooh.takeDamage(100);
	yooh.attack(target);
	yooh.beRepaired(10);
	yooh.highFivesGuys();
	
	return 0;
}