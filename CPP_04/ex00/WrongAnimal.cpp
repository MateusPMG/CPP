/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:05:22 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/12 20:07:47 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	this->type = "WrongAnimal";
	std::cout << "called default WrongAnimal constructor\n";
}

WrongAnimal::WrongAnimal(std::string a_type){
	this->type = a_type;
	std::cout << "called parametric WrongAnimal constructor\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& copy){
	*this = copy;
	std::cout << "called WrongAnimal copy constructor\n";
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
	this->type = copy.get_type();
	std::cout << "called WrongAnimal copy assignment operator\n";
	return (*this);
}

WrongAnimal::~WrongAnimal(){
	std::cout << "called WrongAnimal destructor\n";
}

std::string WrongAnimal::get_type() const {
	return (this->type);
}

void WrongAnimal::makeSound()const{
	std::cout << "wrong!!\n";
}