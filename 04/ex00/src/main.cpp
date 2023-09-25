/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:47 by sanan             #+#    #+#             */
/*   Updated: 2023/09/25 22:41:54 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

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

    

    return (0);
}