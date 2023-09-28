/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 17:23:36 by sanan             #+#    #+#             */
/*   Updated: 2023/09/27 17:32:06 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <ICharacter.hpp>

class Character: public ICharacter {
    private:
        static const int CAPACITY = 4;
        std::string name;
        AMateria* inventory[CAPACITY];

    public:
        Character();
        Character(const Character& ref);
        ~Character();

        Character&	operator=(const Character& ref);

        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
