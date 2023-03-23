/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:44:55 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 21:21:06 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
	private:
	int					_fpValue;
	static const int	_frBits;

	public:
		//ex00
		Fixed();
		Fixed(Fixed const &ref);
		~Fixed();
		
		Fixed&	operator=(Fixed const &ref);

		int		getRawBits() const;
		void	setRawBits(int const raw);

		//ex01
		Fixed(const int raw);
		Fixed(const	float raw);
		

		float	toFloat() const;
		int		toInt() const;
};

std::ostream&	operator<<(std::ostream &os, Fixed const &fixed);

#endif

