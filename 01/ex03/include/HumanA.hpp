/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:40:15 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:44:09 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA{
	private:
	std::string	_name;
	Weapon		&_weapon;

	public:
	HumanA(const std::string name, Weapon& weapon);
	~HumanA();
	void	attack();
};

#endif