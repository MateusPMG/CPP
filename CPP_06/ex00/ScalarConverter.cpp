/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 14:15:33 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/16 21:27:16 by mpatrao          ###   ########.fr       */
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

static int ft_stoi(const std::string& literal){
    int num;
    num = atoi(literal.c_str());
    return num;
}

static double ft_stod(const std::string& literal){
    double num;
    num = std::atof(literal.c_str());
    return num;
}

static float ft_stof(const std::string& literal)
{
    float num;
    num = std::atof(literal.c_str());
    return num;
}

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
    int			len = literal.length();
	long		check = atol(literal.c_str());

	if (len > 10 || check > std::numeric_limits<int>::max()
		|| check < std::numeric_limits<int>::min())
    {
        std::cout << "overflowed int\n";
        exit(1);
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
		else if (literal.at(0) != '-' && !isdigit(literal.at(0)))
			return false;
        else if (!isdigit(literal.at(i)) && i != 0)
            return false;
	}
    return true;
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
        if (!isdigit(literal.at(i)) && i != 0)
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

static bool isPseudoLiteral(const std::string& literal){
    return (literal == "-inff" || literal == "+inff" || literal == "-inf"
    || literal == "+inf" || literal == "nan" || literal == "nanf");
}

static void literalChar(const char literal){
    std::cout << "char: '" << literal << "'" << std::endl;
    std::cout << "int: " << static_cast<int> (literal) << std::endl;
    std::cout << "float: " << static_cast<float> (literal) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double> (literal) << ".0" << std::endl; 
}

static void literalInt(const int literal){        
    if (literal < 256 && literal >= 0 && isprint(literal))
        std::cout << "char: '" << static_cast<char> (literal) << "'" << std::endl;
    else
        std::cout << "char: non displayable\n";
    std::cout << "int: " << literal << std::endl;
    std::cout << "float: " << static_cast<float> (literal) << ".0f" << std::endl;
    std::cout << "double: " << static_cast<double> (literal) << ".0" << std::endl;
}

static void pseudoLiteral(literal_type type, const std::string& literal){
    std::cout << "char: impossible\n";
    std::cout << "int: impossible\n";
    if (type == _float)
    {
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: nan" <<  std::endl;
    }
    else if (type == _double)
    {
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: " << literal << std::endl;
    }
}

static void literalFloat(const float literal){
    if (literal < 256 && literal >= 0 && isprint(literal))
        std::cout << "char: '" << static_cast<char> (literal) << "'" << std::endl;
    else
        std::cout << "char: non displayable\n";
    std::cout << "int: " << static_cast<int> (literal) << std::endl;
    if (literal - floor(literal) != 0.0)
        std::cout << "float: " << literal << "f" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << literal << "f" << std::endl;
    std::cout << "double: " << static_cast<double> (literal) << std::endl; 
}

static void literalDouble(const double literal){
    if (literal < 256 && literal >= 0 && isprint(literal))
        std::cout << "char: '" << static_cast<char> (literal) << "'" << std::endl;
    else
        std::cout << "char: non displayable\n";
    std::cout << "int: " << static_cast<int> (literal) << std::endl;
    if (literal - floor(literal) != 0.0)
        std::cout << "float: " << literal << "f" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << literal << "f" << std::endl;
    std::cout << "double: " << literal << std::endl;
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
			std::cout << "not a char,int,float or double, or overflow try again\n";
			break ;
	}
}