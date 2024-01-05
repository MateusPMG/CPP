/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:07:22 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 18:19:24 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
:AForm("RobotomyRequestForm", 72, 45),_target("Neil"){}

RobotomyRequestForm::RobotomyRequestForm(std::string target)
:AForm("RobotomyRequestForm", 72, 45),_target(target){}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & copy)
:AForm("RobotomyRequestForm", 72, 45),_target(copy._target){}

RobotomyRequestForm::~RobotomyRequestForm(){}

RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const & copy){
	this->_target = copy._target;
	this->setSign(copy.getSign());
	return (*this);
}

void RobotomyRequestForm::executor()const{
	std::cout << "*drilling noises*\n";
	if (std::rand() % 2)
		std::cout << this->_target << " has been robotomized successfully\n";	
	else
		std::cout << "robotomy on " << this->_target << " failed\n";
}