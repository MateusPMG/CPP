/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:04 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/24 16:32:09 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	fixedpt;
		static const int nfb = 8;
	public:
		Fixed();
		Fixed(const Fixed &copy);
		Fixed(const int i);
		Fixed(const float f);
		~Fixed();
		int getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed& operator=(Fixed const &copy);
		float	toFloat(void) const;
		int		toInt(void) const;
};

std::ostream& operator<<(std::ostream &out, Fixed const &fpn);

#endif