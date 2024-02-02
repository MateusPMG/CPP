/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 14:11:18 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/02 14:12:02 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Error: wrong nb of arguments\n";
		return 1;
	}

	BitcoinExchange	btc;
	btc.parse(av[1]);
	return (0);
}