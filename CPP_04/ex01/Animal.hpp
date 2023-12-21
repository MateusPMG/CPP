/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:02:34 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 14:06:36 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Animal{
	protected:
		std::string type;
	public:
		Animal();
		Animal(std::string a_type);
		Animal(const Animal& copy);
		Animal& operator=(const Animal& copy);
		virtual ~Animal();
		std::string get_type()const;
		virtual void makeSound()const;
};