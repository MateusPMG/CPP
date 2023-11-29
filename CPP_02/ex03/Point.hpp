/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:31:19 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/29 15:25:18 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
# include "Fixed.hpp"

class Point{
	private:
		const	Fixed	x;
		const	Fixed	y;
	public:
		Point();
		Point(const float fx, const float fy);
		Point(const Point &copy);
		Point& operator=(Point const &copy);
		~Point();
		Fixed	get_x(void) const;
		Fixed	get_y(void) const;
};

#endif