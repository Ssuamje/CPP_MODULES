/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:44:09 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:46:29 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
    private:
        std::string type;

    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal& ref);
        ~WrongAnimal();

        WrongAnimal&	operator=(const WrongAnimal& ref);

        void makeSound() const;
        std::string getType() const;
};

#endif
