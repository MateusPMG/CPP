/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:39:30 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/29 15:25:36 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(Fixed x1, Fixed y1, Fixed x2, Fixed y2, Fixed x3, Fixed y3){
	Fixed R;
	R = ((x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)) / 2);
	if (R.toInt() < 0)
			R = ((Fixed)(R.toInt()) * -1);
	return (R);
}

bool bsp(Point const a, Point const b, Point const c, Point const point){
	Fixed	T;
	Fixed	A1;
	Fixed	B1;
	Fixed	C1;
	
	T = area(a.get_x(), a.get_y(), b.get_x(), b.get_y(), c.get_x(), c.get_y());
	A1 = area(point.get_x(), point.get_y(), b.get_x(), b.get_y(), c.get_x(), c.get_y());
	B1 = area(a.get_x(), a.get_y(), point.get_x(), point.get_y(), c.get_x(), c.get_y());
	C1 = area(a.get_x(), a.get_y(), b.get_x(), b.get_y(), point.get_x(), point.get_y());
	if (!A1.toInt() || !B1.toInt() || !C1.toInt()){
		std::cout << "The point can't be in a vertex or edge\n";
		return (false);	
	}
	if (T >= (A1 + B1 + C1))
		return (true);
	return (false);
}