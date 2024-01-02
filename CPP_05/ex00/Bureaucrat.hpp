/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:56:49 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/29 15:27:16 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Bureaucrat{
    private:
        const std::string _Name;
        int _Grade;
    public:
        Bureaucrat();
        Bureaucrat(const Bureaucrat& copy);
        Bureaucrat& operator=(const Bureaucrat& copy);
        ~Bureaucrat();
        Bureaucrat(std::string name, int grade);
        std::string getName()const;
        int getGrade()const;
        void increment();
        void decrement();
        void setGrade(int grade);
        class GradeTooLowException : public std::exception
        {
            public:
                const char	*what(void) const throw();
        };
        class GradeTooHighException : public std::exception
        {
            public:
                const char	*what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureau);