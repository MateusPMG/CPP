/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:24:06 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/15 13:53:28 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <string>
#include <iostream>

class Zombie
{
	private:
		std::string	name;
	public:
		void	announce(void);
		std::string	get_name();
		void	set_name(std::string name);
		Zombie(void);
		~Zombie(void);
};

Zombie*	ZombieHorde(int N, std::string name);

#endif