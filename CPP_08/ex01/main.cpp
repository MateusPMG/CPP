/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:21:22 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/01 16:09:21 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
Span sp = Span(5);
sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);
std::cout << sp.shortestSpan() << std::endl;
std::cout << sp.longestSpan() << std::endl;


try
{
    std::cout << "\nTESTING 100000 NUMBERS\n";
	unsigned int		max = 100000;
	Span				s3(max);
	std::vector<int>	v1(max);
	srand(time(NULL));
	std::generate(v1.begin(), v1.end(), std::rand);
	s3.manyAdd(v1.begin(), v1.end());
	std::cout << "Shortest span is: " << s3.shortestSpan() << std::endl;
	std::cout << "Longest span is: " << s3.longestSpan() << std::endl; 
}
catch(const std::exception& e)
{
    std::cerr << e.what() << '\n';
}
return 0;
}