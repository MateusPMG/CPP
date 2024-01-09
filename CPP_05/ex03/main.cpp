/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 13:44:45 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/09 14:47:07 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		delete(rrf);
		rrf = someRandomIntern.makeForm("idk", "idk either");
		delete(rrf);
	}
}