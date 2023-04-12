/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 09:35:06 by sanan             #+#    #+#             */
/*   Updated: 2023/04/12 14:42:09 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP
#define WEAPON_HPP

# include <iostream>

class Weapon {
	private:
	std::string	_type;

	public:
	Weapon();
	~Weapon();
	Weapon(const std::string type);
	const std::string&	getType();
	void				setType(const std::string newType);
};

#endif