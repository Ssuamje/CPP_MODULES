/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 14:38:08 by sanan             #+#    #+#             */
/*   Updated: 2023/09/29 16:18:19 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/AMateria.hpp"

AMateria::AMateria(): type(type) {
    std::cout << "\x1b[33m""[AMateria]: default constructor has called!""\x1b[0m" << std::endl;
}

AMateria::AMateria(AMateria const &ref): type(type) {
    *this = ref;
    std::cout << "\x1b[35m""[AMateria]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

AMateria::~AMateria() {
    std::cout << "\x1b[31m""[AMateria]: destructor has called!""\x1b[0m" << std::endl;
}

AMateria&	AMateria::operator=(AMateria const &ref) {
    if (this != &ref) {
        this->type = ref.type;
        std::cout << "\x1b[34m""[AMateria]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[AMateria]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}

void AMateria::use(ICharacter& target) {
    std::cout << "\x1b[32m""* shoots an Materia at " << target.getName() << " *""\x1b[0m" << std::endl;
}