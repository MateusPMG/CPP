/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:14 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/24 16:33:48 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

static	float ft_pow(float base, int exp)
{
	float	result;

	if (!exp)
		return (1);
	result = base;
	while (--exp)
		result *= base;
	return (result);
}

Fixed::Fixed(void){
	this->fixedpt = 0;
	std::cout << "Default constructor called\n";
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy){
	std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int i){
	this->fixedpt = (i * ft_pow(2, this->nfb));
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f){
	this->fixedpt = roundf(f * ft_pow(2, this->nfb));
	std::cout << "Float constructor called\n";
}

int Fixed::getRawBits(void) const{
	return (this->fixedpt);
}

void Fixed::setRawBits(int const raw){
	this->fixedpt = raw;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called\n";
	this->fixedpt = copy.getRawBits();
	return (*this);
}

float Fixed::toFloat(void) const{
	return(this->fixedpt / ft_pow(2, this->nfb));
}

int	Fixed::toInt(void) const{
	return(this->fixedpt / ft_pow(2, this->nfb));
}

std::ostream	&operator<<(std::ostream &out, Fixed const &fpn)
{
	return (out << fpn.toFloat());
}