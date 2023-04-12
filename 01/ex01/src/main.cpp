/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:37:53 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:21:35 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

#define nZombies 6

int main() {
	Zombie* horde = zombieHorde(nZombies, "HeapZombie");
	
	std::cout << "\n--------------------\n" << std::endl;
	delete[] horde;
}