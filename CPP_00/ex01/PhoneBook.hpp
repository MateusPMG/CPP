/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 15:15:43 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/03 18:02:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include "utils.hpp"
# include <iomanip>
# include <cstdlib>

class PhoneBook
{
	private:
		Contact List[8];
		int	index;
	public:
		PhoneBook();
		~PhoneBook();
		void	ADD(void);
		void	SEARCH(void);
};

#endif