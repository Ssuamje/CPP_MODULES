/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnumLevel.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:24:31 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 18:48:00 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ENUMLEVEL_HPP
# define ENUMLEVEL_HPP

# include <iostream>

enum	Level{
	NONE_EXIST = -1,
	DEBUG,
	INFO,
	WARNING,
	ERROR,
};


class EnumLevel {
	public:
	EnumLevel();
	~EnumLevel();
	static	int	enumize(std::string level);
};

#endif