/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:41:41 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/19 16:31:59 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Brain.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void){
	Animal* array[4];
	for (int i = 0; i < 4; i++)
	{
		if (i <= 1)
			array[i] = new Dog();
		else
			array[i] = new Cat();
	}

	for (int i = 0; i < 4; i++)
		delete array[i];

	std::cout << "\nDeep copy and ideas\n";
		Dog	Max = Dog();
		
		std::cout << "Max ideas\n";
		Max.epiphany(0, "Burglars");
		Max.epiphany(1, "Food");
		Max.ponder(0);
		Max.ponder(1);
		
		Dog	Rex(Max);
		
		std::cout << "Rex copies ideas\n";
		Rex.ponder(0);
		Rex.ponder(1);
		std::cout << "Max new ideas\n";
		Max.epiphany(0, "Sniffing");
		Max.epiphany(1, "Sleep");
		Max.ponder(0);
		Max.ponder(1);
		std::cout << "Rex ideas\n";
		Rex.ponder(0);
		Rex.ponder(1);

		Cat	Salem = Cat();
		
		std::cout << "Salem idea\n";
		Salem.epiphany(0, "Knocking thing off table");
		Salem.ponder(0);
		
		Cat	Sylvester;
		Sylvester = Salem;
		std::cout << "Sylvester copies idea\n";
		Sylvester.ponder(0);
		std::cout << "Sylvester new idea\n";
		Sylvester.epiphany(0, "Tweety");
		Sylvester.ponder(0);
		std::cout << "Salem idea\n";
		Salem.ponder(0);	
	return 0;
}