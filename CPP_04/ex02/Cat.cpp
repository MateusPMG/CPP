/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:03:50 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 14:19:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(){
	std::cout << "called default Cat constructor\n";
	this->type = "Cat";
	this->_Brain = new Brain();
}

Cat::Cat(const Cat& copy):Animal(){
	std::cout << "called Cat copy constructor\n";
	this->type = copy.get_type();
	this->_Brain = new Brain();
	*this->_Brain = *copy._Brain;
}

Cat& Cat::operator=(const Cat& copy){
	std::cout << "called Cat copy assignment operator\n";
	this->type = copy.get_type();
	*this->_Brain = *copy._Brain;
	return (*this);
}

Cat::~Cat(){
	std::cout << "called Cat destructor\n";
	delete this->_Brain;
}

void Cat::makeSound()const{
	std::cout << this->type <<" goes meow\n";
}

void Cat::epiphany(int i, std::string idea){
	this->_Brain->set_idea(i, idea);
}

void Cat::ponder(int i){
	std::cout << this->get_type() << " is thinking about " << this->_Brain->get_idea(i) << "\n";
}

void Cat::f(){}