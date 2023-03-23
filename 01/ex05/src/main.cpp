/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 17:27:09 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:29:54 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Harl.hpp"
#include "../include/EnumLevel.hpp"

int main() {
	std::cout << "----------*NONE_EXIST*----------" << std::endl;
	Harl::complain("HELLO?");

	std::cout << "----------*LEVELS*----------" << std::endl;
	Harl::complain("DEBUG");
	std::cout << "----------------------------" << std::endl;
	Harl::complain("INFO");
	std::cout << "----------------------------" << std::endl;
	Harl::complain("WARNING");
	std::cout << "----------------------------" << std::endl;
	Harl::complain("ERROR");
	std::cout << "----------------------------" << std::endl;

	return 0;
}