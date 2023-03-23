/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:34:18 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 09:20:38 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../include/StringManager.hpp"
#include "../include/FileManager.hpp"
#include <iostream>

int main(int ac, char **av) {
	(void)ac;
	FileManager		fm;
	std::string		extract;

	//checkArgs(ac, av);
	//isFileValid(av[1]);
	fm.setFile(av[1]);
	extract = fm.extractStringFromFile();
	std::cout << extract;
	fm.putStringToFile(extract);
}
