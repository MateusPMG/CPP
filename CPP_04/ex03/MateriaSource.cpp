/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:12:47 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/27 15:53:57 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    std::cout << "Called MateriaSource default constructor\n";
	for (int i = 0; i < 4; i++)
		this->materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& copy){
    std::cout << "Called MateriaSource copy constructor\n";
	for (int i = 0; i < 4; i++)
	{
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
		else
			this->materias[i] = NULL;
	}
}

MateriaSource::~MateriaSource(){
	std::cout << "Called MateriaSource destructor\n";
	for (int i = 0; i < 4 && this->materias[i]; i++)
		delete this->materias[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource& copy){
     std::cout << "Called MateriaSource copy assignment operator\n";
    for (int i = 0; i < 4; i++)
	{
		if (this->materias[i])	
            delete this->materias[i];
		if (copy.materias[i])
			this->materias[i] = copy.materias[i]->clone();
        else
			this->materias[i] = NULL;
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
		if (new_materia)
			delete new_materia;
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
	return (NULL);
}