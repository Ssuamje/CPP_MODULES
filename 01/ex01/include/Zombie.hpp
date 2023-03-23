/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 23:11:38 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 18:48:00 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

# include <iostream>
# define MUMBLE "BraiiiiiiinnnzzzZ..."

class Zombie {
	private :
	std::string _name;
	int			_number;

	public :
	Zombie();
	Zombie(std::string name);
	~Zombie();
	void announce();
	void setName(std::string name);
	void setNumber(int number);
};

Zombie*	zombieHorde(int N, std::string name);

#endif