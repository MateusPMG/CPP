/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:08:55 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/12 20:13:55 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(){
	this->type = "WrongCat";
	std::cout << "called default WrongCat constructor\n";
}

WrongCat::WrongCat(const WrongCat& copy):WrongAnimal(){
	this->type = copy.get_type();
	std::cout << "called WrongCat copy constructor\n";
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
	this->type = copy.get_type();
	std::cout << "called WrongCat copy assignment operator\n";
	return (*this);
}

WrongCat::~WrongCat(){
	std::cout << "called WrongCat destructor\n";
}