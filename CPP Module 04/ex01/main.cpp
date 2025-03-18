/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 16:56:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 17:28:49 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int	main(void)
{
	Animal	*array[42];

	int i = 0;
	while (i < 21)
		array[i ++] = new Dog();
	while (i < 42)
		array[i ++] = new Cat();

	i = 0;
	while (i < 42)
		array[i ++]->makeSound();

	i = 0;
	while (i < 21)
		delete array[i ++];
	while (i < 42)
		delete array[i ++];

	std::cout << std::endl << "Maintenant on test les copies" << std::endl << std::endl;
	Dog	*dog = new Dog();
	dog->setIdea(0, "Jai une super idee");
	Dog *copydog = new Dog(*dog);
	dog->setIdea(1, "Jai une autre super idee");
	std::cout << dog->getIdea(0) << std::endl;
	std::cout << dog->getIdea(1) << std::endl;
	delete dog;
	std::cout << copydog->getIdea(0) << std::endl;
	std::cout << copydog->getIdea(1) << std::endl;
	delete copydog;
}
