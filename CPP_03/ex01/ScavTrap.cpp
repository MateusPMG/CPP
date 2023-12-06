/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:35:45 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 15:24:43 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap():ClapTrap("scavie", 100, 50, 20){
	std::cout << "Called default scavtrap constructor\n";}

ScavTrap::ScavTrap(std::string name):ClapTrap(name, 100, 50, 20){
	std::cout << "Called scavtrap parametric constructor\n";}

ScavTrap::ScavTrap(const ScavTrap& copy):ClapTrap("", 100, 50 ,20){
	std::cout << "Called scavtrap copy constructor\n";
	*this = copy;}

ScavTrap& ScavTrap::operator=(const ScavTrap& copy){
	std::cout << "Called scavtrap copy assignment constructor\n";
	this->Name = copy.get_name();
	this->Hit_points = copy.get_hp();
	this->Energy_points = copy.get_ep();
	this->Attack_damage = copy.get_ad();
	return (*this);}

ScavTrap::~ScavTrap(){
	std::cout << "Called scavtrap destructor\n";}

void ScavTrap::guardGate(){
	std::cout << "ScavTrap: " << this->Name << " is guarding the gate\n";}

void ScavTrap::attack(const std::string& target){
	if (this->Energy_points == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has no energy to execute actions\n";
		return;
	}
	else if (this->Hit_points == 0)
	{
		std::cout << "ScavTrap " << this->Name << " has no hit points to execute actions\n";
		return;
	}
	else if (this->Energy_points != 0){
		this->set_ep(this->Energy_points - 1);
		std::cout << "ScavTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!\n";
	}}