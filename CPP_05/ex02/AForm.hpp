/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:44:10 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 14:37:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        const std::string _Name;
        bool _signed;
        const int _gradeS;
        const int _gradeE;
    public:
        //constructors
        AForm();
        AForm(const AForm& copy);
        AForm(std::string name, int sign_grade, int current_grade);
        
        //overload
        AForm& operator=(const AForm& copy);

        //destructor
        virtual ~AForm();
         
        //getters
        std::string getName()const;
        bool getSign()const;
        int getSignGrade()const;
        int getExecGrade()const;
        
        //public methods
        void beSigned(Bureaucrat& bureau);
        virtual void execute(Bureaucrat const & executor)const = 0;
        
        //exceptions
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

std::ostream& operator<<(std::ostream& out, const AForm& frm);