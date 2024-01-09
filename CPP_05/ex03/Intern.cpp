/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:40 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/09 15:05:15 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &copy){
	*this = copy;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &copy){
	(void)copy;
	return (*this);
}

AForm* Intern::makeShrubberyCreationForm(std::string target){
	return(new ShrubberyCreationForm(target));
}

AForm* Intern::makeRobotomyRequestForm(std::string target){
	return (new RobotomyRequestForm(target));
}

AForm* Intern::makePresidentialPardonForm(std::string target){
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string name, std::string target)
{
	std::string form_name[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm* (Intern::*FormF[3])(std::string target) =
		{&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};
	int i = 0;
	for (; i < 3; i++)
		if (form_name[i] == name)
			return ((this->*FormF[i])(target));
	std::cout << "no form with that name exists\n";
	return (NULL);
}
