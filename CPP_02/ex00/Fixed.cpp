/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:14 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/24 15:11:33 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(){
	this->fixedpt = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(Fixed& copy){
	std::cout << "Copy constructor called\n";
	*this = copy;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called\n";
	return (this->fixedpt);
}

void Fixed::setRawBits(int const raw){
	this->fixedpt = raw;
}

Fixed& Fixed::operator=(Fixed& copy)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedpt = copy.getRawBits();
	return (*this);
}