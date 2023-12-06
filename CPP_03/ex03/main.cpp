/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:21 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 17:47:05 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	c1;
	FragTrap	c2("Larry");
	FragTrap	c3(c1);
	FragTrap	c4;

	c4 = c2;
	for (int i = 0; i < 5; i++)
	{
		c1.attack(c2.get_name());
		c2.takeDamage(c2.get_ad());
	}
	c2.beRepaired(5);
	c2.attack(c1.get_name());
	//
	c3.beRepaired(1);
	for (int i = 0; i < 5; i++)
	{
		c3.attack(c4.get_name());
		c4.takeDamage(c3.get_ad());
		c4.beRepaired(c3.get_ad() / 2);
	}
	for (int i = 0; i < 95; i++)
		c3.attack("Random wall");
	c3.beRepaired(1);
	c3.attack(c4.get_name());
	c3.highFivesGuys();
	return (0);
}