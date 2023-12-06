/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:54:57 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 17:47:52 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap():ClapTrap("fraggie", 100, 100, 30){
	std::cout << "Called default FragTrap constructor\n";}

FragTrap::FragTrap(std::string name):ClapTrap(name, 100, 100, 30){
	std::cout << "Called FragTrap parametric constructor\n";}

FragTrap::FragTrap(const FragTrap& copy):ClapTrap("", 100, 100 ,30){
	std::cout << "Called FragTrap copy constructor\n";
	*this = copy;}

FragTrap& FragTrap::operator=(const FragTrap& copy){
	std::cout << "Called FragTrap copy assignment constructor\n";
	this->Name = copy.get_name();
	this->Hit_points = copy.get_hp();
	this->Energy_points = copy.get_ep();
	this->Attack_damage = copy.get_ad();
	return (*this);}

FragTrap::~FragTrap(){
	std::cout << "Called FragTrap destructor\n";}

void FragTrap::attack(const std::string& target){
	if (this->Energy_points == 0)
	{
		std::cout << "FragTrap " << this->Name << " has no energy to execute actions\n";
		return;
	}
	else if (this->Hit_points == 0)
	{
		std::cout << "FragTrap " << this->Name << " has no hit points to execute actions\n";
		return;
	}
	else if (this->Energy_points != 0){
		this->set_ep(this->Energy_points - 1);
		std::cout << "FragTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!\n";}}

void FragTrap::highFivesGuys(void){
	std::cout << this->Name << " request a high five!\n";}