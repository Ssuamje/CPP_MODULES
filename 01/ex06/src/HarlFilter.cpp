/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:31:56 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:42:54 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HarlFilter.hpp"
#include "../include/EnumLevel.hpp"

void	(*HarlFilter::_func[4])(void) = {
	&HarlFilter::debug,
	&HarlFilter::info,
	&HarlFilter::warning,
	&HarlFilter::error
};

HarlFilter::HarlFilter() {

}

HarlFilter::~HarlFilter() {

}

void	HarlFilter::debug() {
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\nI really do!" <<
	std::endl;
}

void	HarlFilter::info() {
	std::cout <<
	"I cannot believe adding extra bacon costs more money.\nYou didn't put enough bacon in my burger!\nIf you did, I wouldn't be asking for more!" <<
	std::endl;
}

void	HarlFilter::warning() {
	std::cout <<
	"I think I deserve to have some extra bacon for free.\nI've been coming for years whereas you started working here since last month." <<
	std::endl;
}

void	HarlFilter::error() {
	std::cout <<
	"This is unacceptable!\nI want to speak to the manager now." <<
	std::endl;
}

void	HarlFilter::complain(std::string level) {
	int enumLevel = EnumLevel::enumize(level);
	if (enumLevel == NONE_EXIST) {
		std::cout <<
		"Invalid Level!" << std::endl;
		return ;
	}
	switch (enumLevel) {
		case DEBUG:
			HarlFilter::_func[DEBUG]();
		case INFO:
			HarlFilter::_func[INFO]();
		case WARNING:
			HarlFilter::_func[WARNING]();
		case ERROR:
			HarlFilter::_func[ERROR]();
		default:
			std::cout <<
			"This can't be Happen!!!" << std::endl;
			break;
	}
}

