/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:21 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/20 15:23:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	c1;
	ScavTrap	c2("base model");
	ScavTrap	c3(c2);
	ScavTrap	c4;

	c4 = c1;
	c1.attack(c2.get_name());
	c2.takeDamage(50);
	c1.attack(c2.get_name());
	c2.takeDamage(50);
	c1.attack(c2.get_name());
	c2.takeDamage(50);
	c2.beRepaired(4);
	c2.attack(c1.get_name());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 11; i++)
	{
		c3.attack(c4.get_name());
		c4.takeDamage(20);
		c4.beRepaired(1);		
	}
	c3.beRepaired(1);
	c3.guardGate();
	return (0);
}