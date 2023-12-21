/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:02:17 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 13:56:53 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->get_type() << " " << std::endl;
	std::cout << i->get_type() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete j;
	delete i;
	
	const WrongAnimal *wrong_meta = new WrongAnimal();
	const WrongAnimal *wrong_cat = new WrongCat();
	const WrongCat *k = new WrongCat();	
	std::cout << k->get_type() << std::endl;
	std::cout << wrong_cat->get_type() << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();
	k->makeSound();
	delete wrong_meta;
	delete wrong_cat;
	delete k;
}
