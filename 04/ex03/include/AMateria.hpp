/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 13:37:06 by sanan             #+#    #+#             */
/*   Updated: 2023/10/01 21:36:34 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;
class AMateria {
    private:
        AMateria(const AMateria& ref);
        AMateria&	operator=(const AMateria& ref);

    protected:
        AMateria();
        std::string type;

    public:
        virtual ~AMateria();

        AMateria(std::string const & type);
        std::string const & getType() const;

        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};

#endif
