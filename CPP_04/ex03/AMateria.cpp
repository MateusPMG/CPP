/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:35:08 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 15:22:25 by mpatrao          ###   ########.fr       */
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
    
}