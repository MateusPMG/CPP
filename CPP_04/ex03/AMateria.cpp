/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:35:08 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 16:39:06 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(){
    this->type = "none";
}

AMateria::AMateria(std::string const & type){
    this->type = type;
}

AMateria::AMateria(const AMateria& copy){
    this->type = copy.getType();
}

AMateria& AMateria::operator=(const AMateria& copy){
    this->type = copy.getType();
    return (*this);
}

AMateria::~AMateria(){}

std::string const & AMateria::getType()const{
    return (this->type);
}

void AMateria::setType(std::string const & type){
    this->type = type;
}

void AMateria::use(ICharacter& target){
    if (this->type == "ice")
        std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
    else if (this->type == "cure")
        std::cout << "* heals " << target.getName() << "'s wounds *\n";
}