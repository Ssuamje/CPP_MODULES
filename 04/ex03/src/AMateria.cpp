/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:38:08 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 17:00:26 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/AMateria.hpp"

AMateria::AMateria() {
    std::cout << "\x1b[33m""[AMateria]: default constructor has called!""\x1b[0m" << std::endl;
}

AMateria::AMateria(std::string const & type) {
    std::cout << "\x1b[33m""[AMateria]: type constructor has called!""\x1b[0m" << std::endl;
    this->type = type;
}

AMateria::AMateria(AMateria const &ref) {
    std::cout << "\x1b[35m""[AMateria]: deep-copy constructor has called!""\x1b[0m" << std::endl;
    *this = ref;
}

AMateria::~AMateria() {
    std::cout << "\x1b[31m""[AMateria]: destructor has called!""\x1b[0m" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const &ref) {
    std::cout << "Trying to assign" << ref.type << " to another!" << std::endl;
    throw std::runtime_error("This doesn't make sense!\n");
}

std::string const & AMateria::getType() const {
    return (this->type);
}

void AMateria::use(ICharacter& target) {
    std::cout << "\x1b[32m""* shoots " << this->type << " at " << target.getName() << " *""\x1b[0m" << std::endl;
}