/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:59:04 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:21:30 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "\x1b[33m""[Animal]: default constructor has called!""\x1b[0m" << std::endl;
}

Animal::Animal(Animal const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Animal]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Animal::~Animal() {
    std::cout << "\x1b[31m""[Animal]: destructor has called!""\x1b[0m" << std::endl;
}

Animal&	Animal::operator=(Animal const &ref) {
    if (this != &ref) {
        this->type = ref.getType();
        std::cout << "\x1b[34m""[Animal]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Animal]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string Animal::getType() const {
    return (this->type);
}

void Animal::makeSound() const {
    std::cout << "\x1b[32m""[" << this->getType() << "]: (Seems Don't know how to say)""\x1b[0m" << std::endl;
}
