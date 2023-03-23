/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:58:05 by sanan             #+#    #+#             */
/*   Updated: 2023/03/23 21:21:23 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>

#include "../include/Fixed.hpp"

const int	Fixed::_frBits = 8;

Fixed::Fixed() {
	this->_fpValue = 0;
	std::cout << "\x1b[33m""[Fixed]: default constructor has called!""\x1b[0m" << std::endl;
}

Fixed::Fixed(Fixed const &ref) {
	*this = ref;
	std::cout << "\x1b[35m""[Fixed]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Fixed::~Fixed() {
	std::cout << "\x1b[31m""[Fixed]: destructor has called!""\x1b[0m" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const &ref) {
	if (this != &ref) {
		_fpValue = ref.getRawBits();
		std::cout << "\x1b[34m""[Fixed]: assign operator has called!""\x1b[0m" << std::endl;
	}
	else
		std::cout << "\x1b[34m""[Fixed]: assign operator with same instance!""\x1b[0m" << std::endl;
	return *this;
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits has called!" << std::endl;
	return _fpValue;
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits has called!" << std::endl;
	_fpValue = raw;
}

//ex01 below

Fixed::Fixed(const int raw) {
	std::cout << "\x1b[33m""[Fixed]: int constructor has called!""\x1b[0m" << std::endl;
	_fpValue = raw << _frBits;
}

Fixed::Fixed(const float raw) {
	std::cout << "\x1b[35m""[Fixed]: float constructor has called!""\x1b[0m" << std::endl;
	_fpValue = (int)roundf(raw * (1 << _frBits));
}

std::ostream&	operator<<(std::ostream &os, Fixed const &fixed) {
	os << fixed.toFloat();
	return os;
}

float	Fixed::toFloat() const {
	return (float)_fpValue / (float)(1 << _frBits);
}

int		Fixed::toInt() const {
	return (int)(_fpValue >> _frBits);
}
