/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:03:50 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/12 19:48:51 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	this->type = "Cat";
	std::cout << "called default Cat constructor\n";
}

Cat::Cat(const Cat& copy):Animal(){
	this->type = copy.get_type();
	std::cout << "called Cat copy constructor\n";
}

Cat& Cat::operator=(const Cat& copy){
	this->type = copy.get_type();
	std::cout << "called Cat copy assignment operator\n";
	return (*this);
}

Cat::~Cat(){
	std::cout << "called Cat destructor\n";
}

void Cat::makeSound()const{
	std::cout << this->type <<" goes meow\n";
}