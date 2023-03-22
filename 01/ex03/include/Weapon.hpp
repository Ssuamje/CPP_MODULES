/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:35:06 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 11:28:49 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class Weapon {
	private:
	std::string	_type;

	public:
	Weapon();
	~Weapon();
	Weapon(std::string type);
	std::string	getType();
	void		setType(std::string newType);
};

#endif