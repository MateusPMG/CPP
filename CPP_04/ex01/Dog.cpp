/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:04:12 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/19 13:46:57 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	std::cout << "called default Dog constructor\n";
	this->type = "Dog";
	this->_Brain = new Brain();
}


Dog::Dog(const Dog& copy):Animal(){
	std::cout << "called Dog copy constructor\n";
	this->type = copy.get_type();
	this->_Brain = new Brain();
	this->_Brain = copy._Brain;
}

Dog& Dog::operator=(const Dog& copy){
	std::cout << "called Dog copy assignment operator\n";
	this->type = copy.get_type();
	this->_Brain = copy._Brain;
	return (*this);
}

Dog::~Dog(){
	std::cout << "called Dog destructor\n";
	delete this->_Brain;
}

void Dog::makeSound()const{
	std::cout << this->type <<" goes bark\n";
}