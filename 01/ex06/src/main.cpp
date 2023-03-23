/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:27:09 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:57:58 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/HarlFilter.hpp"
#include "../include/EnumLevel.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout <<
		"Argment count is wrong!" << std::endl;
		return (EXIT_FAILURE);
	}
	std::string	level = av[1];
	int			enumLevel = EnumLevel::enumize(level);
	if (enumLevel == NONE_EXIST) {
		std::cout <<
		"[ " << "Probably complaining about insignificant problems" << " ]" << std::endl;
		return (EXIT_FAILURE);
	}
	std::cout <<
	"[ " << level << " ]" << std::endl;
	HarlFilter::complain(level);

	return 0;
}