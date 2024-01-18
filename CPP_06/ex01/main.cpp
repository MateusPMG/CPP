/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:17:28 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/18 15:25:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(void)
{
	Data a;
	a.string = "well you know i mean";
	a.value = 400000;
	
	uintptr_t b;
	
	b = Serializer::serialize(&a);

	Data* c;
	c = Serializer::deserialize(b);

	std::cout << "data object a, string: " << a.string << std::endl;
	std::cout << "data object a, value: " << a.value << std::endl;
	std::cout << "data pointer c, string: " << c->string << std::endl;
	std::cout << "data pointer c, value: " << c->value << std::endl;
}