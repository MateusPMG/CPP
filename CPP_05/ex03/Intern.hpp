/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 13:41:01 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/10 13:55:50 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    public:
        Intern();
        Intern(const Intern& copy);
        ~Intern();
        Intern& operator=(const Intern& copy);
        AForm* makeForm(std::string name, std::string target);
        AForm* makeShrubberyCreationForm(std::string target);
        AForm* makeRobotomyRequestForm(std::string target);
        AForm* makePresidentialPardonForm(std::string target);
        class	InvalidFormNameException : public std::exception
		{
			public:
				const char	*what(void) const throw();
		};
};