/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:58:49 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 13:04:30 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal {
    private:
        std::string type;

    public:
        Animal();
        Animal(const Animal& ref);
        virtual ~Animal();

        Animal&	operator=(const Animal& ref);

        virtual std::string getType() const;
        virtual void makeSound() const;
};

#endif
