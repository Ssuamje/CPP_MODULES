/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanan <sanan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 22:06:47 by sanan             #+#    #+#             */
/*   Updated: 2023/10/01 21:35:51 by sanan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"
#include "../include/Cat.hpp"
#include "../include/Dog.hpp"

void leaks() {
    system("leaks abstract");
}

int main()
{
    // const Animal* animal = new Animal(); <- compile error because it's abstract class
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    cat->makeSound(); //will output the cat sound!
    dog->makeSound();
    // animal->makeSound();

    std::cout << std::endl;

    // delete animal;
    delete dog;
    delete cat;

    atexit(leaks);
    return (0);
}
