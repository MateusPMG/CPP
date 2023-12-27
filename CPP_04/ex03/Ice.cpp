/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:10:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 14:47:11 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
    std::cout << "Called Ice default constructor\n";
    this->type = "ice";
}

Ice::Ice(const Ice& copy): AMateria(copy){
    (void)copy;
    std::cout << "Called Ice copy constructor\n";
    this->type = "ice";
}

Ice& Ice::operator=(const Ice& copy){
    (void)copy;
    std::cout << "Called Ice copy assignment operator\n";
	this->type = "ice";
    return (*this);
}

Ice::~Ice(){
    std::cout << "Called Ice destructor\n";
}

AMateria* Ice::clone()const{
    AMateria* r = new Ice();
    return (r);
}

void Ice::use(ICharacter &target)
{
	std::cout <<  "* shoots an ice bolt at " << target.getName() << " *\n";
}