/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:47 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 13:13:55 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

Animal** createAnimalsInEvenDogsOddCats(int count) {
    Animal **animals = new Animal*[count];
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    return animals;
}

int main()
{
    int countOfAnimals = 100;
    Animal** animals = createAnimalsInEvenDogsOddCats(countOfAnimals);
    
    std::cout << "------------------" << std::endl;

    for (int i = 0; i < countOfAnimals; i++) {
        delete animals[i];
    }
    delete animals;
    return (0);
}
