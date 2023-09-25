/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 21:58:11 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:31:21 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal {
    private:
        std::string type;

    public:
        Cat();
        Cat(const Cat& ref);
        ~Cat();

        Cat&	operator=(const Cat& ref);

        std::string getType() const;
        void makeSound() const;
};

#endif
