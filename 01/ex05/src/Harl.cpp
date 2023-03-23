/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:56 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:31:20 by sanan            ###   ########.fr       */
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
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" <<
	std::endl;
}

void	Harl::info() {
	std::cout <<
	"I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" <<
	std::endl;
}

void	Harl::warning() {
	std::cout <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." <<
	std::endl;
}

void	Harl::error() {
	std::cout <<
	"This is unacceptable! I want to speak to the manager now." <<
	std::endl;
}

void	Harl::complain(std::string level) {
	int enumLevel = EnumLevel::enumize(level);
	if (enumLevel == NONE_EXIST) {
		std::cout <<
		"Invalid Level!" << std::endl;
		return ;
	}
	switch (enumLevel)
	{
	case DEBUG:
		Harl::_func[DEBUG]();
		break;
	case INFO:
		Harl::_func[INFO]();
		break;
	case WARNING:
		Harl::_func[WARNING]();
		break;
	case ERROR:
		Harl::_func[ERROR]();
		break;
	default:
		std::cout <<
		"This can't be Happen!!!" << std::endl;
		break;
	}
}

