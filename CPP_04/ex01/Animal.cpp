/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:02:42 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/12 19:29:47 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(){
	this->type = "animal";
	std::cout << "called default animal constructor\n";
}

Animal::Animal(std::string a_type){
	this->type = a_type;
	std::cout << "called parametric animal constructor\n";
}

Animal::Animal(const Animal& copy){
	*this = copy;
	std::cout << "called animal copy constructor\n";
}

Animal& Animal::operator=(const Animal& copy){
	this->type = copy.get_type();
	std::cout << "called animal copy assignment operator\n";
	return (*this);
}

Animal::~Animal(){
	std::cout << "called animal destructor\n";
}

std::string Animal::get_type() const {
	return (this->type);
}

void Animal::makeSound()const{
	std::cout << "well\n";
}