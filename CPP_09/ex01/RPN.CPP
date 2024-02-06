/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.CPP                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:54:25 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/06 19:20:49 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

enum literals {zero = '0', one = '1', two = '2', three = '3', four = '4', five = '5', six = '6',
	seven = '7', eight = '8', nine = '9',
	plus = '+', minus = '-', multi = '*', divi = '/'};

RPN::RPN(){}

RPN::RPN(const RPN& copy){
    *this = copy;
}

RPN& RPN::operator=(const RPN& copy){
    this->_stack = copy._stack;
    return (*this);
}

RPN::~RPN(){}

void RPN::calculate(char c){
    if (_stack.size() < 2)
		throw(std::runtime_error("Not enough numbers to perform operations"));
	int	first;
	int	second;
	second = _stack.top();
	_stack.pop();
	first = _stack.top();
	_stack.pop();
	switch (c)
	{
		case '+':
			_stack.push(first + second);
			break;
		case '-':
			_stack.push(first - second);
			break;
		case '*':
			_stack.push(first * second);
			break;
		case '/':
			if (second == 0)
				throw(std::runtime_error("Division by 0!!!"));
			_stack.push(first / second);
			break;
	}
}

void RPN::parse(std::string input){
    std::stringstream	in(input);
	std::string			str;
	while (in >> str)
		if (str.size() > 1)
			throw(std::runtime_error("Error: use numbers between 0 and 9"));
	in.clear();
    in.seekg(0, std::ios::beg);
	if (in.peek() == std::stringstream::traits_type::eof())
		throw(std::runtime_error("Error: input is empty"));
    char c;
    while (in >> c)
	{
		switch (c)
		{
		case zero:
		case one:
		case two:
		case three:
		case four:
		case five:
		case six:
		case seven:
		case eight:
		case nine:
			_stack.push(c - '0');
			break;
		case plus:
		case minus:
		case multi:
		case divi:
			calculate(c);
			break;
		default:
			throw(std::runtime_error("Error: forbidden character"));
		}
	}
    if (_stack.size() > 1)
		throw(std::runtime_error("Error: more than 1 number in stack"));
	std::cout << _stack.top() << std::endl;
}   