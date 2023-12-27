/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:35:08 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 14:03:58 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << "Called AMateria default constructor\n";
}

AMateria::AMateria(std::string const & type){
    std::cout << "Called AMateria constructor\n";
    this->type = type;
}

AMateria::AMateria(const AMateria& copy){
    std::cout << "Called AMateria copy constructor\n";
    this->type = copy.getType();
}

AMateria& AMateria::operator=(const AMateria& copy){
    std::cout << "Called AMateria copy assignment operator\n";
    this->type = copy.getType();
    return (*this);
}

AMateria::~AMateria(){
    std::cout << "Called AMateria destructor\n";
}

std::string const & AMateria::getType()const{
    return (this->type);
}

void AMateria::setType(std::string const & type){
    this->type = type;
}

void AMateria::use(ICharacter& target){
    std::cout << this->type << " was used on " << target.getName();
}