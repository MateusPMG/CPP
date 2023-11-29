/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:14 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/28 17:11:42 by mpatrao          ###   ########.fr       */
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
	//std::cout << "Default constructor called\n";
}

Fixed::~Fixed(){
	//std::cout << "Destructor called\n";
}

Fixed::Fixed(const Fixed &copy){
	//std::cout << "Copy constructor called\n";
	*this = copy;
}

Fixed::Fixed(const int i){
	this->fixedpt = (i * ft_pow(2, this->nfb));
	//std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float f){
	this->fixedpt = roundf(f * ft_pow(2, this->nfb));
	//std::cout << "Float constructor called\n";
}

int Fixed::getRawBits(void) const{
	return (this->fixedpt);
}

void Fixed::setRawBits(int const raw){
	this->fixedpt = raw;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	//std::cout << "Copy assignment operator called\n";
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

bool Fixed::operator>(Fixed const &bigger) const{
	return (this->fixedpt > bigger.fixedpt);
}

bool Fixed::operator<(Fixed const &smaller) const{
	return (this->fixedpt < smaller.fixedpt);
}

bool Fixed::operator>=(Fixed const &BoE) const{
	return (this->fixedpt >= BoE.fixedpt);
}

bool Fixed::operator<=(Fixed const &SoE) const {
	return (this->fixedpt <= SoE.fixedpt);
}

bool Fixed::operator==(Fixed const &Equal) const{
	return (this->fixedpt == Equal.fixedpt);
}

bool Fixed::operator!=(Fixed const &Diff) const{
	return (this->fixedpt != Diff.fixedpt);
}

Fixed Fixed::operator+(Fixed const &summ){
	Fixed	answr;
	answr.setRawBits(fixedpt + summ.fixedpt);
	return (answr);
}

Fixed Fixed::operator-(Fixed const &subtrct){
	Fixed	answr;
	answr.setRawBits(fixedpt - subtrct.fixedpt);
	return (answr);
}

Fixed Fixed::operator*(Fixed const &multply){
	Fixed	answr;
	answr.setRawBits((((int64_t)this->fixedpt * (int64_t)multply.fixedpt)) / ft_pow(2, this->nfb));
	return (answr);
}

Fixed Fixed::operator/(Fixed const &divisn){
	Fixed	answr;
	answr.setRawBits((((int64_t)this->fixedpt * ft_pow(2, this->nfb)) / (int64_t)divisn.fixedpt));
	return (answr);
}

Fixed Fixed::operator++(void){
	this->setRawBits(this->fixedpt + 1);
	return (*this);
}

Fixed Fixed::operator++(int post_incrmnt){
	Fixed	answr(*this);
	(void)post_incrmnt;
	this->setRawBits(this->fixedpt + 1);
	return (answr);
}

Fixed Fixed::operator--(void){
	this->setRawBits(this->fixedpt - 1);
	return (*this);
}

Fixed Fixed::operator--(int post_dcrmnt){
	Fixed	answr(*this);
	(void)post_dcrmnt;
	this->setRawBits(this->fixedpt - 1);
	return (*this);
}

Fixed &Fixed::min(Fixed &n1, Fixed &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::min(Fixed const &n1, Fixed const &n2)
{
	if (n1 < n2)
		return (n1);
	return (n2);
}

Fixed	&Fixed::max(Fixed &n1, Fixed &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}

const Fixed	&Fixed::max(Fixed const &n1, Fixed const &n2)
{
	if (n1 > n2)
		return (n1);
	return (n2);
}