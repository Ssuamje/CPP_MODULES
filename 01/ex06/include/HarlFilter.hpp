/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HarlFilter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:17:41 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 17:43:19 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef HARLFILTER_HPP
# define HARLFILTER_HPP

#include <iostream>

class	HarlFilter {
	private:
	static	void	(*_func[4])(void);
	static	void	debug();
	static	void	info();
	static	void	warning();
	static	void	error();

	public:
	HarlFilter();
	~HarlFilter();
	static	void	complain(std::string level);
};

#endif