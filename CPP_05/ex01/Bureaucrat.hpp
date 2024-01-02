/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:56:49 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/02 16:34:48 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Form.hpp"

class Form;

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
        void signForm(Form& frm, bool sign);
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