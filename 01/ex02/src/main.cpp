/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 08:45:51 by sanan             #+#    #+#             */
/*   Updated: 2023/03/22 09:31:17 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main() {
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout <<
	"string addr: " << &string << std::endl <<
	"stringPTR: " << stringPTR << std::endl <<
	"stringREF addr: " << &stringREF << std::endl;
	std::cout <<
	"\n--------------------\n" << std::endl;
	std::cout <<
	"string: " << string << std::endl <<
	"stringPTR value: " << *stringPTR << std::endl <<
	"stringREF: " << stringREF << std::endl;
}