/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:04 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/28 14:49:56 by mpatrao          ###   ########.fr       */
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
		float	toFloat(void) const;
		int		toInt(void) const;
		Fixed& operator=(Fixed const &copy);
		bool operator>(Fixed const &bigger) const;
		bool operator<(Fixed const &smaller) const;
		bool operator>=(Fixed const &BoE) const;
		bool operator<=(Fixed const &SoE) const;
		bool operator==(Fixed const &Equal) const;
		bool operator!=(Fixed const &Diff) const;
		Fixed operator+(Fixed const &summ);
		Fixed operator-(Fixed const &subtrct);
		Fixed operator*(Fixed const &multply);
		Fixed operator/(Fixed const &divisn);
		Fixed operator++(void);
		Fixed operator++(int post_incrmnt);
		Fixed operator--(void);
		Fixed operator--(int post_decrmnt);
		static Fixed& min(Fixed &n1, Fixed &n2);
		static const Fixed& min(Fixed const &n1, Fixed const &n2);
		static Fixed& max(Fixed &n1, Fixed &n2);
		static const Fixed& max(Fixed const &n1, Fixed const &n2);
		
};

std::ostream& operator<<(std::ostream &out, Fixed const &fpn);

#endif