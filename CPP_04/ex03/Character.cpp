/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:15:46 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 16:52:01 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character(){
    
}

Character::Character(const std::string name){
    this->Name = name;
}

Character::Character(const Character& copy){
    this->Name = copy.getName();
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete (this->inventory[i]);
    for (int i = 0; i < 4; i++)
        this->inventory[i] = copy.inventory[i];
}

Character& Character::operator=(const Character& copy){
    this->Name = copy.getName();
    for (int i = 0; i < 4; i++)
        if (this->inventory[i])
            delete (this->inventory[i]);
    for (int i = 0; i < 4; i++)
        this->inventory[i] = copy.inventory[i];
    return (*this);
}

Character::~Character(){
    
}

std::string const & Character::getName()const{
    return (this->Name);
}

void Character::equip(AMateria* m){
    for (int i = 0; i < 4; i++)
    {
        if (this->inventory[i] == 0)
            this->inventory[i] = m;
    }
}

void Character::unequip(int idx){
    
}

void Character::use(int idx, ICharacter& target){
    if (this->inventory[idx])
        this->inventory[idx]->use(target);
}