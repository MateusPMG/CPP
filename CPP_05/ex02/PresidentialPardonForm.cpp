/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 16:50:57 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 17:19:15 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
:AForm("PresidentialPardonForm", 25, 5),_target("Neil"){}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
:AForm("PresidentialPardonForm", 25, 5),_target(target){}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm& const copy)
:AForm("PresidentialPardonForm", 25, 5),_target(copy._target){}

PresidentialPardonForm::~PresidentialPardonForm(){}

PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm& const copy){
	this->_target = copy._target;
	this->setSign(copy.getSign());
	return (*this);
}

void PresidentialPardonForm::executor()const{
	std::cout << this->_target << " has been pardoned by president Zaphod Beeblebrox\n";
}