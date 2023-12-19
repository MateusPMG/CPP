/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:41:41 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/19 13:23:54 by mpatrao          ###   ########.fr       */
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
	return 0;
}