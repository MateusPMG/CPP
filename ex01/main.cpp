/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 12:40:30 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/07 14:03:47 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

int	main(void)
{
	PhoneBook	Phonebook;
	std::string	input;
	while (1)
	{
		std::cout << "Enter ADD, SEARCH or EXIT.\n";
		std::cin.clear();
		std::getline(std::cin, input);
		if (std::cin.eof())
		{
			std::cout << std::endl;
			std::exit(0);
		}
		if (input == "ADD")
			Phonebook.ADD();
		else if (input == "SEARCH")
			Phonebook.SEARCH();
		else if (input == "EXIT")
			return (0);
		else 
			std::cout << "Error: invalid command\n";
	}
	return (0);
}