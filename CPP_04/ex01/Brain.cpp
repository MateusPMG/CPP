/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:03:52 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/19 14:54:40 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(){
	std::cout << "called default brain constructor\n";
}

Brain::Brain(const Brain& copy){
	std::cout << "called brain copy constructor\n";
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy){
	std::cout << "called brain copy assignment\n";
	for (int i = 0; i < 100; i++)
		this->ideas[i] = copy.get_idea(i);
	return (*this);
}

Brain::~Brain(){
	std::cout << "called brain destructor\n";
}

std::string	Brain::get_idea(int index) const
{
	return (this->ideas[index]);
}

void		Brain::set_idea(int index, std::string idea)
{
	this->ideas[index] = idea;
}

