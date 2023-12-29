/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:56:23 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/29 15:41:12 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	bureau_life(std::string name, int grade)
{
	Bureaucrat desk_jockey(name, grade);

	std::cout << desk_jockey << std::endl;
	desk_jockey.increment();
	desk_jockey.increment();
	desk_jockey.increment();
	std::cout << desk_jockey << std::endl;
	desk_jockey.decrement();
	desk_jockey.decrement();
	desk_jockey.decrement();
	desk_jockey.decrement();
	std::cout << desk_jockey << std::endl;
	desk_jockey.setGrade(desk_jockey.getGrade() + 5);
	std::cout << desk_jockey << std::endl;
	desk_jockey.setGrade(desk_jockey.getGrade() - 10);
	std::cout << desk_jockey << std::endl;
	return (0);
}

int	error_testing(std::string name, int grade)
{
	try
	{
		bureau_life(name, grade);
	}
	catch(Bureaucrat::GradeTooHighException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	catch(Bureaucrat::GradeTooLowException &error)
	{
		std::cerr << error.what() << std::endl;
		return (1);
	}
	return (0);
}

int	main(void)
{
	error_testing("pencil_pusher", 0);
	error_testing("pencil_pusher", 151);
	error_testing("pencil_pusher", 2);
	error_testing("pencil_pusher", 150);
	error_testing("pencil_pusher", 145);
	error_testing("pencil_pusher", 3);
	error_testing("pencil_pusher", 75);
	return (0);
}