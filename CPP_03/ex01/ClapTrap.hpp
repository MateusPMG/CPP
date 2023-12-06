/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:37 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 14:33:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap
{
	protected:
		std::string		Name;
		unsigned int	Hit_points;
		unsigned int	Energy_points;
		unsigned int	Attack_damage;
	public:
		ClapTrap();
		ClapTrap(std::string name);
		ClapTrap(ClapTrap& copy);
		ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		~ClapTrap();
		ClapTrap& operator=(ClapTrap& copy);
		void	set_hp(unsigned int hp);
		void	set_ep(unsigned int ep);
		void	set_ad(unsigned int ad);
		std::string		get_name(void)const;
		unsigned int	get_hp(void)const;
		unsigned int	get_ep(void)const;
		unsigned int	get_ad(void)const;
		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif