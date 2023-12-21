/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:10:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 16:03:23 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice(){
    this->type = "ice";
}

Ice::Ice(const Ice& copy){
    this->type = copy.getType();
}

Ice& Ice::operator=(const Ice& copy){
    this->type = copy.getType();
    return (*this);
}

Ice::~Ice(){
    
}

AMateria* Ice::clone()const{
    AMateria* r = new Ice();
    return (r);
}