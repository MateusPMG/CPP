/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:12:11 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/21 14:50:54 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string newName, Weapon& newWeapon):weapon(newWeapon)
{
	this->name = newName;
}

void	HumanA::attack(void)
{
	std::cout << name << " attacks with their weapon " << weapon.getType()
	<< std::endl;
}