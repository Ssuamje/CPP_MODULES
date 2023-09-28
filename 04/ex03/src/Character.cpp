/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:23:12 by sanan             #+#    #+#             */
/*   Updated: 2023/09/27 17:33:48 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Character.hpp"

Character::Character() {
    for (int i = 0; i < Character::CAPACITY; i++)
        this->inventory[i] = NULL;
    std::cout << "\x1b[33m""[Character]: default constructor has called!""\x1b[0m" << std::endl;
}

Character::Character(Character const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Character]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Character::~Character() {
    std::cout << "\x1b[31m""[Character]: destructor has called!""\x1b[0m" << std::endl;
}

Character&	Character::operator=(Character const &ref) {
    if (this != &ref) {
        //compose deep-copy with your own class!
        std::cout << "\x1b[34m""[Character]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Character]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

std::string const & Character::getName() const {
    return (this->name);
}

void Character::equip(AMateria* m) {
    for (int i = 0; i < Character::CAPACITY; i++) {
        if (this->inventory[i] == NULL) {
            this->inventory[i] = m;
            break ;
        }
    }
}

void Character::unequip(int idx) {
    if (idx < 0 || idx >= Character::CAPACITY)
        return ;
    this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target) {
    if (idx < 0 || idx >= Character::CAPACITY)
        return ;
    this->inventory[idx]->use(target);
}