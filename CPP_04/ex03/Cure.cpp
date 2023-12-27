/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:18:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 15:01:33 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
    std::cout << "Called Cure default constructor\n";
    this->type = "cure";
}

Cure::Cure(const Cure& copy): AMateria(copy){
    (void)copy;
	std::cout << "Called Cure copy constructor\n";
    this->type = "cure";
}

Cure& Cure::operator=(const Cure& copy){
    (void)copy;
    std::cout << "Called Cure copy assignment operator\n";
	this->type = "cure";
    return (*this);
}

Cure::~Cure(){
    std::cout << "Called Cure destructor\n";
}

AMateria* Cure::clone()const{
    AMateria* r = new Cure();
    return (r);
}

void Cure::use(ICharacter &target)
{
	std::cout <<  "* heals " << target.getName() << "'s wounds *\n";
}