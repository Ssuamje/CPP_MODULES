/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:47 by sanan             #+#    #+#             */
/*   Updated: 2023/09/26 12:03:56 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    std::cout << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    std::cout << dog->getType() << " " << std::endl;
    std::cout << std::endl;

    cat->makeSound(); //will output the cat sound!
    dog->makeSound();
    animal->makeSound();

    std::cout << std::endl;

    delete animal;
    delete dog;
    delete cat;

    std::cout << "************************" << std::endl;

    const WrongAnimal* wrongAnimal = new WrongAnimal();
    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    std::cout << std::endl;

    wrongCat->makeSound(); //will output the wrong animal sound
    wrongAnimal->makeSound();

    delete wrongAnimal;
    delete wrongCat;
    return (0);
}