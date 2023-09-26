/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:45:41 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 12:03:43 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/WrongCat.hpp"

WrongCat::WrongCat() {
    this->type = "WrongCat";
    std::cout << "\x1b[33m""[WrongCat]: default constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::WrongCat(WrongCat const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[WrongCat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << "\x1b[31m""[WrongCat]: destructor has called!""\x1b[0m" << std::endl;
}

WrongCat&	WrongCat::operator=(WrongCat const &ref) {
    if (this != &ref) {
        this->type = ref.getType();
        std::cout << "\x1b[34m""[WrongCat]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[WrongCat]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string WrongCat::getType() const {
    return (this->type);
}

void WrongCat::makeSound() const {
    // std::cout << "\x1b[32m""[" << this->getType() << "]: Meow Meow!""\x1b[0m" << std::endl;
    std::cout << "\x1b[32m""[CAT]: Meow Meow!""\x1b[0m" << std::endl;
}
