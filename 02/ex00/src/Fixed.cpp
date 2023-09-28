/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 18:58:05 by sanan             #+#    #+#             */
/*   Updated: 2023/09/28 13:23:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Fixed.hpp"

const int	Fixed::_frBits = 8;

Fixed::Fixed() {
	std::cout << "\x1b[33m""[Fixed]: default constructor has called!""\x1b[0m" << std::endl;
	this->_fpValue = 0;
}

Fixed::Fixed(Fixed const& ref) {
	std::cout << "\x1b[35m""[Fixed]: deep-copy constructor has called!""\x1b[0m" << std::endl;
	*this = ref;
}

Fixed::~Fixed() {
	std::cout << "\x1b[31m""[Fixed]: destructor has called!""\x1b[0m" << std::endl;
}

Fixed&	Fixed::operator=(Fixed const& ref) {
	if (this != &ref) {
		std::cout << "\x1b[34m""[Fixed]: copy operator has called!""\x1b[0m" << std::endl;
		_fpValue = ref.getRawBits();
	}
	return (*this);
}

int		Fixed::getRawBits() const {
	std::cout << "getRawBits has called!" << std::endl;
	return (_fpValue);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits has called!" << std::endl;
	_fpValue = raw;
}
