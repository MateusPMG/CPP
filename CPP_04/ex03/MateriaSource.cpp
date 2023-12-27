/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:12:47 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 14:48:46 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "Called MateriaSource default constructor\n";
}

MateriaSource::MateriaSource(const MateriaSource& copy){
    std::cout << "Called MateriaSource copy constructor\n";
	for (int i = 0; i < 4 && copy.materias[i]; i++)
			this->materias[i] = copy.materias[i]->clone();
}

MateriaSource::~MateriaSource(){
   
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
     std::cout << "Called MateriaSource copy assignment operator\n";
    for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
        else
            this->materias[i] = 0;
	}
    return (*this);
}

void MateriaSource::learnMateria(AMateria* new_materia){
    int	i = 0;
	if (!new_materia)
	{
		std::cout << "Can't learn non-existent materias\n";
		return ;
	}
	if (this->materias[3])
	{
		std::cout << "Can't learn any more materias\n";
		return ;
	}
	for(; i < 4 && this->materias[i]; i++)
        ;
	this->materias[i] = new_materia;
	std::cout << "Learned new materia " << new_materia->getType() << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4 && this->materias[i]; i++)
	{
		if (type == this->materias[i]->getType())
			return (this->materias[i]->clone());
	}
	std::cout << "No matching materia type to create\n";
	return (0);
}