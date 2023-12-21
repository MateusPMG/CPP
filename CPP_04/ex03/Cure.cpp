/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:18:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 15:18:59 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(){
    this->type = "Cure";
}

Cure::Cure(const Cure& copy){
    this->type = copy.getType();
}

Cure& Cure::operator=(const Cure& copy){
    this->type = copy.getType();
    return (*this);
}

Cure::~Cure(){
    
}