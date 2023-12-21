/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:10:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 15:17:52 by mpatrao          ###   ########.fr       */
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