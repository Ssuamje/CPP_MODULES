/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:44:02 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 12:03:38 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal {
    private:
        std::string type;

    public:
        WrongCat();
        WrongCat(const WrongCat& ref);
        ~WrongCat();

        WrongCat&	operator=(const WrongCat& ref);

        void makeSound() const;
        std::string getType() const;
};

#endif
