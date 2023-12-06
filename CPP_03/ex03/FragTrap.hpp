/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:54:48 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 18:46:53 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "ClapTrap.hpp"

class FragTrap:public virtual ClapTrap{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		FragTrap(const FragTrap& copy);
		FragTrap& operator=(const FragTrap& copy);
		~FragTrap();
		void attack(const std::string& target);
		void highFivesGuys(void);
	protected:
		static const unsigned int	hp = 100;
		static const unsigned int	ad = 30;
};