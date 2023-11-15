/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:24:16 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/13 16:10:08 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void	Zombie::announce(void)
{
	std::cout << Zombie::name << ": BraiiiiiiinnnzzzZ...\n";
}

Zombie::Zombie(void)
{
	//constructor
}

Zombie::~Zombie(void)
{
	//print message with name of zombie destroyed
	std::cout << Zombie::name << " was Destroyed\n";
}

std::string	Zombie::get_name(void)
{
	return (this->name);
}

void	Zombie::set_name(std::string name)
{
	this->name = name;
}