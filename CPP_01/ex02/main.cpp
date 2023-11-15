/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 14:37:27 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/15 15:05:31 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int	main(void)
{
	std::string	string = "HI THIS I BRAIN";
	std::string* ptr = &string;
	std::string& ref = string;
	
	std::cout << "mem adress of string var: " << &string << std::endl;
	std::cout << "mem adress held by ptr: " << ptr << std::endl;
	std::cout << "mem adress held by ref: " << &ref << std::endl;

	std::cout << "value of string: " << string << std::endl;
	std::cout << "value pointed to by ptr: " << *ptr << std::endl;
	std::cout << "value pointed to by ref: " << ref << std::endl;
	
}