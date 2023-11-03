/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:26:28 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/03 18:08:18 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	this->index = 0;
}

PhoneBook::~PhoneBook()
{
	//destructor
}

void	PhoneBook::ADD(void)
{
	Contact	Ncontact;
	Ncontact.set_first_name(get_input("Enter first name: "));
	Ncontact.set_last_name(get_input("Enter last name: "));
	Ncontact.set_nickname(get_input("Enter nickname: "));
	Ncontact.set_phone_number(get_input("Enter phone number: "));
	Ncontact.set_darkest_secret(get_input("Enter darkest secret: "));
	if (this->index == 8)
		this->index = 0;
	this->List[this->index] = Ncontact;
	this->index++;
	std::cout << "Contact added\n";
}

void PhoneBook::SEARCH(void)
{
	int	i;
	int	j;
	std::string first_name;
	std::string last_name;
	std::string nickname;
	std::string	input;
	if (this->List[0].get_first_name() == "")
	{
		std::cout << "No contacts to display.\n";
		return ;
	}
	std::cout << "     Index|First Name| Last Name|  Nickname" << '\n';
	i = 0;
	while (i < 8 && this->List[i].get_first_name() != "")
	{
		std::cout << std::setw(10) << i << "|";
		first_name = this->List[i].get_first_name();
		last_name = this->List[i].get_last_name();
		nickname = this->List[i].get_nickname();
		if (first_name.length() > 10)
			first_name = first_name.substr(0, 9) + ".";
		if (last_name.length() > 10)
			last_name = last_name.substr(0, 9) + ".";
		if (nickname.length() > 10)
			nickname = nickname.substr(0, 9) + ".";
		std::cout << std::setw(10) << first_name << "|";
		std::cout << std::setw(10) << last_name << "|";
		std::cout << std::setw(10) << nickname << std::endl;
		i++;
	}
	while (1)
	{
		input = get_input("Enter the index you wish to view");
		j = std::atoi(input.c_str());
		if (j >= 0 && j <= 7 && this->List[j].get_first_name() != "")
			break;
		std::cout << "Error: invalid index\n";
	}
	this->List[j].print_contact();
}