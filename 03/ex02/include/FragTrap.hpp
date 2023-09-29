/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:35:30 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 15:44:25 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {
	private:

	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap& ref);
		~FragTrap();

		FragTrap&	operator=(const FragTrap& ref);
		
		void	highFivesGuys();
};

#endif
