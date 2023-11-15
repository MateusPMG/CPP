/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:23:54 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/15 13:58:11 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie*	Zombie;
	Zombie = ZombieHorde(5, "manel");
	for(int i = 0; i < 5;i++)
		Zombie[i].announce();
	delete[] Zombie;
	return (0);
}