/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:17:41 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 18:50:12 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>

class	Harl {
	private:
	static	void	(*_func[4])(void);
	static	void	debug();
	static	void	info();
	static	void	warning();
	static	void	error();

	public:
	Harl();
	~Harl();
	static	void	complain(std::string level);
};

#endif