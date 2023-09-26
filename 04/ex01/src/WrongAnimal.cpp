/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:45:33 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:47:04 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
    this->type = "WrongAnimal";
    std::cout << "\x1b[33m""[WrongAnimal]: default constructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[WrongAnimal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "\x1b[31m""[WrongAnimal]: destructor has called!""\x1b[0m" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(WrongAnimal const &ref) {
    if (this != &ref) {
        this->type = ref.getType();
        std::cout << "\x1b[34m""[WrongAnimal]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[WrongAnimal]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const {
    return (this->type);
}

void WrongAnimal::makeSound() const {
    std::cout << "\x1b[32m""[" << this->getType() << "]: (Seems Don't know how to say)""\x1b[0m" << std::endl;
}
