/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:59:12 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:33:47 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() {
    this->type = "Cat";
    std::cout << "\x1b[33m""[Cat]: default constructor has called!""\x1b[0m" << std::endl;
}

Cat::Cat(Cat const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Cat]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Cat::~Cat() {
    std::cout << "\x1b[31m""[Cat]: destructor has called!""\x1b[0m" << std::endl;
}

Cat&	Cat::operator=(Cat const &ref) {
    if (this != &ref) {
        this->type = ref.getType();
        std::cout << "\x1b[34m""[Cat]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Cat]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string Cat::getType() const {
    return (this->type);
}

void Cat::makeSound() const {
    // std::cout << "\x1b[32m""[" << this->getType() << "]: Meow Meow!""\x1b[0m" << std::endl;
    std::cout << "\x1b[32m""[CAT]: Meow Meow!""\x1b[0m" << std::endl;
}
