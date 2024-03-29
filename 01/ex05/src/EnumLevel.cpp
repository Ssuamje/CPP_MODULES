/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnumLevel.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:27:41 by sanan             #+#    #+#             */
/*   Updated: 2023/09/12 18:31:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/EnumLevel.hpp"

EnumLevel::EnumLevel() {

}

EnumLevel::~EnumLevel() {

}

int EnumLevel::enumize(std::string level) {
	std::string str[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (level == str[i])
			return (i);
	}
	return (NONE_EXIST);
}
