/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 14:50:53 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/22 15:16:53 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl	harl1;
	std::string	levels[5] = {"DEBUG", "INFO", "WARNING", "ERROR", ""};
	int	lvl;
	if (ac == 2)
	{
		for (lvl = 0; lvl <= 4; lvl++)
		{
			if (levels[lvl] == av[1])
				break;
		}
		switch(lvl){
			case 3:
				harl1.complain("ERROR");
				break;
			case 2:
				harl1.complain("WARNING");
				harl1.complain("ERROR");
				break;
			case 1:
				harl1.complain("INFO");
				harl1.complain("WARNING");
				harl1.complain("ERROR");
				break;
			case 0:
				harl1.complain("DEBUG");
				harl1.complain("INFO");
				harl1.complain("WARNING");
				harl1.complain("ERROR");
				break;
			default:
				std::cout << "Probably complaining about insignificant problems\n";
		}
	}
	else
		std::cout << "Error: one and only argument\n";
	return (0);
}