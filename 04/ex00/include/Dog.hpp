/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:58:13 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:29:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal {
    private:
        std::string type;

    public:
        Dog();
        Dog(const Dog& ref);
        ~Dog();

        Dog&	operator=(const Dog& ref);

        std::string getType() const;
        void makeSound() const;
};

#endif
