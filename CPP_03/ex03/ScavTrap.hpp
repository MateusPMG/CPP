/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:35:49 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 18:46:59 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "ClapTrap.hpp"

class ScavTrap:public virtual ClapTrap{
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad);
		ScavTrap(const ScavTrap& copy);
		ScavTrap& operator=(const ScavTrap& copy);
		~ScavTrap();
		void attack(const std::string& target);
		void guardGate();
	protected:
		static const unsigned int ep = 50;
};