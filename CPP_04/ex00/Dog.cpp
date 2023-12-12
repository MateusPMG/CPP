/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:04:12 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/12 19:48:41 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(){
	this->type = "Dog";
	std::cout << "called default Dog constructor\n";
}


Dog::Dog(const Dog& copy):Animal(){
	this->type = copy.get_type();
	std::cout << "called Dog copy constructor\n";
}

Dog& Dog::operator=(const Dog& copy){
	this->type = copy.get_type();
	std::cout << "called Dog copy assignment operator\n";
	return (*this);
}

Dog::~Dog(){
	std::cout << "called Dog destructor\n";
}

void Dog::makeSound()const{
	std::cout << this->type <<" goes bark\n";
}