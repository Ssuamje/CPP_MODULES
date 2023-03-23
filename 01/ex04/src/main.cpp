/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 22:34:18 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 18:46:47 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/FileManager.hpp"
#include <iostream>

std::string replaceString(std::string origin, std::string from, std::string to) {
    std::string result;
    size_t start_pos = 0;
    size_t pos;

    while ((pos = origin.find(from, start_pos)) != std::string::npos) {
        result += origin.substr(start_pos, pos - start_pos) + to;
        start_pos = pos + from.length();
    }

    result += origin.substr(start_pos);
	return (result);
}

int	isArgsValid(int ac, char **av) {
	std::string str;

	if (ac != 4)
		return (false);
	for (int i = 1; i < ac; i++) {
		str = av[i];
		if (str.empty())
			return (false);
	}
	if (str.empty())
		return (false);
	return (true);
}

int main(int ac, char **av) {
	FileManager		fm;
	std::string		extract;

	if (isArgsValid(ac, av) == false
	||	fm.isFileValid(av[1]) == false)
		return (EXIT_FAILURE);
	fm.setFile(av[1]);
	extract = fm.extractStringFromFile();
	extract = replaceString(extract, av[2], av[3]);
	fm.putStringToFile(extract);
}
