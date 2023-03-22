/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:21:10 by sanan             #+#    #+#             */
/*   Updated: 2023/03/21 23:34:47 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

int main() {
	Zombie stackZombie("StackZombie");
	Zombie *heapZombie = newZombie("HeapZombie");
	randomChump("randomStackZombie");

	std::cout <<
	"\n--------------------\n" << std::endl;

	delete heapZombie;
}