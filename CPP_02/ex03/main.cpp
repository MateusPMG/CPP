/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:25:09 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/29 15:33:58 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point	p1(1, 1);
	Point	p2(1, 10);
	Point	p3(-10, 1);
	Point	p4(-3, 3);

	if (bsp(p1, p2, p3, p4))
	{
		std::cout << "Point is inside triangle\n";
		return (0);		
	}
	else
	{
		std::cout << "Point is NOT inside triangle\n";
		return (1);		
	}
}