/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:13:52 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/12 16:50:48 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <limits>

class ScalarConverter{
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
	public:
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();
		static void convert(const std::string& literal);
};