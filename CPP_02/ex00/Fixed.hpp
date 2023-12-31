/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:36:04 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/24 14:48:06 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	fixedpt;
		static const int nfb = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(Fixed& copy);
		int getRawBits(void) const;
		void	setRawBits(int const raw);
		Fixed& operator=(Fixed& copy);
};

#endif