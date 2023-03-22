/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:11:38 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 08:08:30 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# define MUMBLE "BraiiiiiiinnnzzzZ..."

class Zombie {
	private :
	std::string _name;

	public :
	Zombie(std::string name);
	~Zombie();
	void announce();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);

#endif