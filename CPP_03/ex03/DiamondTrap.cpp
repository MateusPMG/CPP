/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:50:24 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/20 15:33:24 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():FragTrap("Minion_clap_name", FragTrap::hp, ScavTrap::ep, FragTrap::ad),ScavTrap("Minion_clap_name", FragTrap::hp, ScavTrap::ep, FragTrap::ad){
	this->Name = "Minion";
	std::cout << "Called default DiamondTrap constructor\n";}

DiamondTrap::DiamondTrap(std::string name):FragTrap(name + "_clap_name", FragTrap::hp, ScavTrap::ep, FragTrap::ad), ScavTrap(name + "_clap_name", FragTrap::hp, ScavTrap::ep, FragTrap::ad){
	this->Name = name;
	std::cout << "Called DiamondTrap parametric constructor\n";}

DiamondTrap::DiamondTrap(const DiamondTrap& copy):ClapTrap(),FragTrap(),ScavTrap(){
	std::cout << "Called DiamondTrap copy constructor\n";
	*this = copy;}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& copy){
	std::cout << "Called DiamondTrap copy assignment \n";
	this->Name = copy.Name;
	this->ClapTrap::Name = copy.Name + "_clap_name";
	this->Hit_points = copy.get_hp();
	this->Energy_points = copy.get_ep();
	this->Attack_damage = copy.get_ad();
	return (*this);}

DiamondTrap::~DiamondTrap(){
	std::cout << "Called DiamondTrap destructor\n";}

void DiamondTrap::attack(const std::string& target){
	this->ScavTrap::attack(target);}	

void DiamondTrap::whoAmI(){
	std::cout << this->Name << ": My name is " << this->Name << " and my ClapTrap name is " << this->ClapTrap::Name << std::endl;}