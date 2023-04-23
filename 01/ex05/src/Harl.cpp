/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:56 by sanan             #+#    #+#             */
/*   Updated: 2023/04/23 16:03:32 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include "../include/EnumLevel.hpp"

void	(*Harl::_func[4])(void) = {
	&Harl::debug,
	&Harl::info,
	&Harl::warning,
	&Harl::error
};

Harl::Harl() {

}

Harl::~Harl() {

}

void	Harl::debug() {
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" <<
	std::endl;
}

void	Harl::info() {
	std::cout <<
	"I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" <<
	std::endl;
}

void	Harl::warning() {
	std::cout <<
	"I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." <<
	std::endl;
}

void	Harl::error() {
	std::cout <<
	"This is unacceptable!\nI want to speak to the manager now." <<
	std::endl;
}

void	Harl::complain(std::string level) {
	int enumLevel = EnumLevel::enumize(level);
	if (enumLevel == NONE_EXIST) {
		std::cout <<
		"Invalid Level!" << std::endl;
		return ;
	}
	Harl::_func[enumLevel]();
}

