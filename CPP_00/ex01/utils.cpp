/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 16:07:31 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/07 14:03:25 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

int	spaces_only(std::string input)
{
	for (int i = 0; input[i]; i++)
		if (!std::isspace(input[i]))
			return (0);
	return (1);
}

std::string	get_input(std::string prompt)
{
	std::string	input;
	while (1)
	{
		std::cout << prompt << '\n';
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}
		if (!input.empty() && !spaces_only(input))
			return (input);
		std::cout << "Error: invalid input\n";
	}
}