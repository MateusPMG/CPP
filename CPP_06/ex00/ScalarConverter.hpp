/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:13:52 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/11 15:31:51 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class ScalarConverter{
	public:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& copy);
		ScalarConverter& operator=(const ScalarConverter& copy);
		~ScalarConverter();
		void convert()const;
};