/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 12:44:49 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 13:11:53 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "../include/Brain.hpp"

Brain::Brain() {
    std::cout << "\x1b[33m""[Brain]: default constructor has called!""\x1b[0m" << std::endl;
}

Brain::Brain(Brain const &ref) {
    *this = ref;
    std::cout << "\x1b[35m""[Brain]: deep-copy constructor has called!""\x1b[0m" << std::endl;
}

Brain::~Brain() {
    std::cout << "\x1b[31m""[Brain]: destructor has called!""\x1b[0m" << std::endl;
}

Brain&	Brain::operator=(Brain const &ref) {
    if (this != &ref) {
        for (int i = 0; i < this->COUNT; i++){
            this->ideas[i] = ref.ideas[i];
        }
        std::cout << "\x1b[34m""[Brain]: assign operator has called!""\x1b[0m" << std::endl;
    }
    else
        std::cout << "\x1b[34m""[Brain]: assign operator with same instance!""\x1b[0m" << std::endl;
    return (*this);
}
