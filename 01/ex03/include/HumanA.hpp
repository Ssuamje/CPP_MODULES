/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HUmanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:40:15 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 11:27:44 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HUMANA_HPP
#define HUMANA_HPP

# include "Weapon.hpp"
# include <iostream>

class HumanA{
	private:
	std::string	_name;
	Weapon		&_weapon;
	
	public:
	HumanA(std::string name, Weapon& weapon);
	~HumanA();
	void	attack();
};

#endif