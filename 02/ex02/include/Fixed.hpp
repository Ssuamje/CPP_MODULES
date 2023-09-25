/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:44:55 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 15:47:36 by sanan            ###   ########.fr       */
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

		//ex02
		// comparison
		bool	operator>(Fixed const &ref) const;
		bool	operator<(Fixed const &ref) const;
		bool	operator>=(Fixed const &ref) const;
		bool	operator<=(Fixed const &ref) const;
		bool	operator==(Fixed const &ref) const;
		bool	operator!=(Fixed const &ref) const;
		
		// arithmetic
		Fixed	operator+(Fixed const &ref) const;
		Fixed	operator-(Fixed const &ref) const;
		Fixed	operator*(Fixed const &ref) const;
		Fixed	operator/(Fixed const &ref) const;

		//increment, decrement
		Fixed&	operator++();
		Fixed	operator++(int);
		Fixed&	operator--();
		Fixed	operator--(int);


		static Fixed& min(Fixed &a, Fixed &b);
		static const Fixed& min(Fixed const &a, Fixed const &b);
		static Fixed& max(Fixed &a, Fixed &b);
		static const Fixed& max(Fixed const &a, Fixed const &b);
};

std::ostream&	operator<<(std::ostream &os, Fixed const &fixed);


#endif

