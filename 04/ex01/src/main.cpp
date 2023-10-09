/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:47 by sanan             #+#    #+#             */
/*   Updated: 2023/10/09 11:39:49 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

const Animal** createAnimalsInEvenDogsOddCats(int count) {
    const Animal **animals = new const Animal*[count];
    for (int i = 0; i < count; i++) {
        if (i % 2 == 0)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }
    return animals;
}

void leaks() {
    system("leaks brains");
}

int main()
{
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    delete dog;
    delete cat;

    std::cout << "------------------" << std::endl;

    int countOfAnimals = 4;
    const Animal** animals = createAnimalsInEvenDogsOddCats(countOfAnimals);

    std::cout << "------------------" << std::endl;

    for (int i = 0; i < countOfAnimals; i++) {
        delete animals[i];
    }
    delete animals;
    atexit(leaks);
    return (0);
}
