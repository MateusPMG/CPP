/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:15:46 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 16:00:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
    std::cout << "Called Character default constructor\n";
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const std::string name){
    std::cout << "Called Character constructor with name " << name << std::endl;
    this->Name = name;
	for (int i = 0; i < 4; i++)
		this->inventory[i] = NULL;
}

Character::Character(const Character& copy){
    std::cout << "Called Character copy constructor\n";
    this->Name = copy.getName();
    for (int i = 0; i < 4; i++)
        this->inventory[i] = copy.inventory[i]->clone();
}

Character& Character::operator=(const Character& copy){
    std::cout << "Called Character copy assignment operator\n";
    this->Name = copy.getName();
    for (int i = 0; i < 4 && copy.inventory[i]; i++)
        this->inventory[i] = copy.inventory[i]->clone();
    return (*this);
}

Character::~Character(){
	for (int i = 0; i < 4 && this->inventory[i]; i++)
		delete this->inventory[i];
    std::cout << "Called Character destructor for " << this->Name << std::endl;
}

std::string const & Character::getName()const{
    return (this->Name);
}

void Character::equip(AMateria* m){
    int i = 0;
    if (!m)
	{
		std::cout << "Non-existent inventory can't be equipped\n";
		return ;
	}
    for (; i < 4; i++)
    {
        if (!this->inventory[i])
			break ;
        if (i == 3 && this->inventory[i])
		{
			std::cout << this->Name << "'s inventory is full. Can't equip " << m->getType() << std::endl;
			return ;	
		}
    }
    this->inventory[i] = m;
    std::cout << this->Name << " equipped " << m->getType() << " on slot " << i << std::endl;
}

void Character::unequip(int idx){
    if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index, must be in range [0-3]\n";
		return ;
	}
	if (!this->inventory[idx])
	{
		std::cout << "There is nothing equipped in slot " << idx << std::endl;
		return ;
	}
	std::cout << this->Name << " unequipped " << this->inventory[idx]->getType() << " from slot " << idx << std::endl;
	this->inventory[idx] = NULL;
}

void Character::use(int idx, ICharacter& target){
    if (idx < 0 || idx > 3)
	{
		std::cout << "Invalid index, must be in range [0-3]\n";
		return ;
	}
    if (!this->inventory[idx])
	{
		std::cout << "There is nothing in slot " << idx << " to use\n";
		return ;
	}
    this->inventory[idx]->use(target);
}