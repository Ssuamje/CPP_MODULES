/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:28:48 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 08:40:44 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name) {
	Zombie*	horde = new Zombie[N];

	for (int i = 0; i < N; i++) {
		horde[i].setName(name);
		horde[i].setNumber(i);
		horde[i].announce();
	}
	return (horde);
}
