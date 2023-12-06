/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 14:09:47 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/06 18:50:07 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): Name("Zero"), Hit_points(10), Energy_points(10), Attack_damage(0){
	std::cout << "Called default ClapTrap constructor\n";}

ClapTrap::ClapTrap(std::string name){
	std::cout << "Called default ClapTrap constructor with name " << name << std::endl;
	this->Name = name;
	this->Hit_points = 10;
	this->Energy_points = 10;
	this->Attack_damage = 0;}

ClapTrap::ClapTrap(std::string name, unsigned int hp, unsigned int ep, unsigned int ad){
	std::cout << "Called default constructor with name " << name << " and given stats\n";
	this->Name = name;
	this->Hit_points = hp;
	this->Energy_points = ep;
	this->Attack_damage = ad;}

ClapTrap::ClapTrap(ClapTrap& copy){
	std::cout << "Called copy constructor\n";
	this->Name = copy.get_name();
	this->Hit_points = copy.get_hp();
	this->Energy_points = copy.get_ep();
	this->Attack_damage = copy.get_ad();}

ClapTrap::~ClapTrap(){
	std::cout << "Called destructor for " << this->Name << std::endl;}

ClapTrap& ClapTrap::operator=(ClapTrap& copy){
	std::cout << "Called copy assignment operator\n";
	this->Name = copy.get_name();
	this->Hit_points = copy.get_hp();
	this->Energy_points = copy.get_ep();
	this->Attack_damage = copy.get_ad();
	return (*this);}

void ClapTrap::set_hp(unsigned int hp){
	this->Hit_points = hp;}

void ClapTrap::set_ep(unsigned int ep){	
	this->Energy_points = ep;}

void ClapTrap::set_ad(unsigned int ad){	
	this->Attack_damage = ad;}

std::string ClapTrap::get_name(void)const{
	return (this->Name);}

unsigned int ClapTrap::get_hp(void)const{
	return (this->Hit_points);}

unsigned int ClapTrap::get_ep(void)const{
	return (this->Energy_points);}

unsigned int ClapTrap::get_ad(void)const{
	return (this->Attack_damage);}

void ClapTrap::attack(const std::string& target){
	if (this->Energy_points == 0)
		std::cout << "ClapTrap " << this->Name << " has no energy to execute actions\n";
	else if (this->Hit_points == 0)
		std::cout << "ClapTrap " << this->Name << " has no hit points to execute actions\n";
	else if (this->Energy_points != 0){
		this->set_ep(this->Energy_points - 1);
		std::cout << "ClapTrap " << this->Name << " attacks " << target << ", causing " << this->Attack_damage << " points of damage!\n";
	}}

void ClapTrap::takeDamage(unsigned int amount){
	if (this->Hit_points != 0)
	{
		std::cout << this->Name << " takes " << amount << " damage\n";
		if (amount <= this->Hit_points)
			this->set_hp(this->Hit_points - amount);
		else
			this->set_hp(0);}
	else
		std::cout << this->Name <<  " has no hit points left can't take damage\n";}

void ClapTrap::beRepaired(unsigned int amount){
	if (this->Hit_points == 0)
	{
		std::cout << this->get_name() <<  " has no hit points, can't repair\n";
		return;
	}
	else if (this->Energy_points == 0)
	{
		std::cout << this->get_name() << " repaired " << amount << " hit points\n";
		return;
	}
	else if (this->Energy_points != 0){
		this->set_hp(this->Hit_points + amount);
		this->set_ep(this->Energy_points - 1);
		std::cout << this->get_name() << " has been repaired, gaining: " << amount << " hit points\n";}}