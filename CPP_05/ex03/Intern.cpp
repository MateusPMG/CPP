/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:49:40 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/10 13:56:54 by mpatrao          ###   ########.fr       */
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
	AForm	*new_form;
	const std::string	forms[3] =
		{"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm	*(Intern::*form_func[3])(std::string target) =
		{&Intern::makeShrubberyCreationForm, &Intern::makeRobotomyRequestForm, &Intern::makePresidentialPardonForm};

	for (unsigned long i = 0; i < name.length(); i++)
		name[i] = tolower(name[i]);
	for (int i = 0; i < 3; i++)
		if (name == forms[i])
			return (new_form = (this->*form_func[i])(target));
	throw(InvalidFormNameException());
	return (0);
}

const char	*Intern::InvalidFormNameException::what(void) const throw()
{
	return ("Form name is invalid");
}