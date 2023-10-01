/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:59:18 by sanan             #+#    #+#             */
/*   Updated: 2023/10/01 21:34:10 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() {
    this->type = "Dog";
    this->brain = new Brain();
    std::cout << "\x1b[33m""[Dog]: default constructor has called!""\x1b[0m" << std::endl;
}

Dog::Dog(Dog const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Dog]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Dog::~Dog() {
    delete this->brain;
    std::cout << "\x1b[31m""[Dog]: destructor has called!""\x1b[0m" << std::endl;
}

Dog&	Dog::operator=(Dog const &ref) {
    if (this != &ref) {
        this->type = ref.getType();
        if (this->brain)
            delete this->brain;
        this->brain = new Brain(*ref.brain);
        std::cout << "\x1b[34m""[Dog]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Dog]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string Dog::getType() const {
    return (this->type);
}

void Dog::makeSound() const {
    // std::cout << "\x1b[32m""[" << this->getType() << "]: Woof Woof!""\x1b[0m" << std::endl;
    std::cout << "\x1b[32m""[DOG]: Woof Woof!""\x1b[0m" << std::endl;
}
