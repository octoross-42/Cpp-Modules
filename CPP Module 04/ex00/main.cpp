/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 16:17:42 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongDog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();
	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	cat->makeSound();
	dog->makeSound();
	animal->makeSound();
	delete animal;
	delete dog;
	delete cat;

	std::cout << std::endl << "Now the wrong animals" << std::endl << std::endl;
	const WrongAnimal* wrongAnimal = new WrongAnimal();
	const WrongAnimal* wrongDog = new WrongDog();
	const WrongAnimal* wrongCat = new WrongCat();
	std::cout << wrongDog->getType() << " " << std::endl;
	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrongDog->makeSound();
	wrongAnimal->makeSound();
	delete wrongAnimal;
	delete wrongCat;
	delete wrongDog;
}
