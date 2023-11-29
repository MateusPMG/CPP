/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 14:46:51 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/29 15:09:04 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point():x(Fixed(0)),y(Fixed(0)){}

Point::Point(const float fx, const float fy):x(fx),y(fy){}

Point::Point(Point const &copy):x(copy.get_x()),y(copy.get_y()){}

Point& Point::operator=(Point const &copy){
	(void)copy;
	return (*this);
}

Point::~Point(){}

Fixed Point::get_x(void)const{
	return (this->x);
}

Fixed Point::get_y(void)const{
	return(this->y);
}