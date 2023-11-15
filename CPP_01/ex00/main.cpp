/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:23:54 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/13 16:19:57 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*Zombie;
	Zombie = NULL;
	Zombie = newZombie("newbie");
	randomChump("chump");
	Zombie->announce();
	delete Zombie;
	return (0);
}