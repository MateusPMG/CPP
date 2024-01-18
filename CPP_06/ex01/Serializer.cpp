/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 14:57:42 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/18 15:28:30 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& copy){
	(void)copy;
}

Serializer& Serializer::operator=(const Serializer& copy){
	(void)copy;
	return (*this);
}

Serializer::~Serializer(){}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t> (ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*> (raw));
}