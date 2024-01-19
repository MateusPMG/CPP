/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 14:38:08 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/19 15:13:18 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>

Base* generate(void){
	int randNum = (rand() * 1.0 / RAND_MAX * 3) + 1;

	switch (randNum)
	{
		case 1:
			return (new A());
			break;
		case 2:
			return (new B());
			break;
		case 3:
			return (new C());
			break;
		default:
			std::cout << "Failed to create a pointer\n";
			return NULL;
	}
}

void identify(Base* p){
	if (dynamic_cast<A*>(p))
		std::cout << "pointer of type A\n";
	else if (dynamic_cast<B*>(p))
		std::cout << "pointer of type B\n";
	else if (dynamic_cast<C*>(p))
		std::cout << "pointer of type C\n";
}

void identify(Base& p){
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "reference of type A\n";
	}
	catch(const std::exception& error)
	{}

	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "reference of type B\n";
	}
	catch(const std::exception& error)
	{}

	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "reference of type C\n";
	}
	catch(const std::exception& error)
	{}
}

int main(void)
{
	Base	*ptr;

	for (int i = 0; i < 10; i++)
	{
		ptr = generate();

		identify(ptr);
		identify(*ptr);
		if (ptr)
			delete ptr;
		std::cout << std::endl;
	}
}