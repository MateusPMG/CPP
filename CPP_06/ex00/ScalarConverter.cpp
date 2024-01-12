/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:15:33 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/12 17:49:28 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* constructors, copy assignment overload, destructor */
/*  */

ScalarConverter::ScalarConverter(){};

ScalarConverter::ScalarConverter(const ScalarConverter& copy){
	(void) copy;
	return ;
};

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& copy){
	(void)copy;
	return (*this);
};

ScalarConverter::~ScalarConverter(){};


/* actual methods */
/*  */

enum literal_type {error,_pseudo_literal,_char,_int,_float,_double};

static bool isChar(const std::string& literal)
{
	if (literal.length() != 1)
		return (false);
	if (literal.at(0) < std::numeric_limits<char>::min()
     || literal.at(0) > std::numeric_limits<char>::max()
     || isdigit(literal.at(0)))
            return (false);
    return (true);
}

static bool isInt(const std::string& literal)
{
	for (size_t i = literal.at(0) == '-' ? 1 : 0; i < literal.length(); i++) 
	{
        if (!isdigit(literal.at(i)))
            return (false);
    }
    return (true);
}

static bool isFloat(const std::string& literal)
{
	if (literal == "-inff" || literal == "+inff" || literal == "nanf")
        return (true);
	if (literal.at(literal.length() - 1) != 'f')
		return (false);
	for (size_t i = 0; i < literal.length() - 1; i++)
	{
		if (literal.at(i) == '.')
		{
			if (i == 0 || i == literal.length() - 1 || literal.find('.') != i)
				return false;
		}
		else if (!isdigit(literal.at(i)))
			return false;
	}
}

static bool isDouble(const std::string& literal)
{
    bool    found_point;
    found_point = false;
    if (literal == "-inf" || literal == "+inf" || literal == "nan")
        return true;
    for (size_t i = 0; i < literal.length(); i += 1)
    {
        if (literal.at(i) == '.' && found_point)
            return false;
        else if (literal.at(i) == '.')
        {
            found_point = true;
            continue ;
        }
        if (!isdigit(literal.at(i)))
            return false;
    }
    return true;
}

static literal_type getType(const std::string& literal)
{
	if (isChar(literal))
		return (_char);
	if (isInt(literal))
		return (_int);
	if (isFloat(literal))
		return (_float);
	if (isDouble(literal))
		return (_double);
	return (error);
}

void ScalarConverter::convert(const std::string& literal){
	switch(getType(literal))
	{
        case _char:
            literalChar(literal.at(0));
            break ;

        case _int:
            literalInt(ft_stoi(literal));
            break ;

        case _float:
            if (isPseudoLiteral(literal))
                pseudoLiteral(_float, literal);
            else
                literalFloat(ft_stof(literal));
            break ;

        case _double:
            if (isPseudoLiteral(literal))
                pseudoLiteral(_double, literal);
            else
                literalDouble(ft_stod(literal));
            break ;
		default:
			std::cout << "not a char,int,float or double, try again\n";
			break ;
	}
}