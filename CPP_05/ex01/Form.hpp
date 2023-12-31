/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:44:10 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/02 16:35:00 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form{
    private:
        const std::string _Name;
        bool _signed;
        const int _gradeS;
        const int _gradeE;
    public:
        Form();
        Form(const Form& copy);
        Form& operator=(const Form& copy);
        ~Form();
        Form(std::string name, int sign_grade, int current_grade);
        std::string getName()const;
        bool getSign()const;
        int getSignGrade()const;
        int getExecGrade()const;
        void beSigned(Bureaucrat& bureau);
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

std::ostream& operator<<(std::ostream& out, const Form& frm);