/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnumLevel.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:27:41 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:30:36 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/EnumLevel.hpp"

EnumLevel::EnumLevel() {

}

EnumLevel::~EnumLevel() {

}

int EnumLevel::enumize(std::string level) {
	if (level == "DEBUG")
		return (DEBUG);
	if (level == "INFO")
		return (INFO);
	if (level == "WARNING")
		return (WARNING);
	if (level == "ERROR")
		return (ERROR);
	return (NONE_EXIST);
}
