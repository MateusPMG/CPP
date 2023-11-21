/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:12:18 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/21 15:07:55 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newname)
{
	this->name = newname;
}

void	HumanB::setWeapon(Weapon& newWeapon)
{
	this->weapon = &newWeapon;
}

void	HumanB::attack(void)
{
	std::cout << name << " attacks with their weapon " << weapon->getType()
	<< std::endl;
}