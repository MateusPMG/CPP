/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:43:57 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/02 16:41:07 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_Name("default"),_signed(false),_gradeS(75),_gradeE(75){
    std::cout << "called form default constructor\n";
}

Form::Form(const Form& copy):_Name(copy._Name),_signed(copy._signed),_gradeS(copy._gradeS),_gradeE(copy._gradeE){
    std::cout << "called form copy constructor\n";
}

Form& Form::operator=(const Form& copy){
    std::cout << "called form copy assignment\n";
    this->_signed = copy._signed;
    return (*this);
}

Form::~Form(){
    std::cout << "called form destructor\n";
}

Form::Form(std::string name, int sign_grade, int current_grade):_Name(name),_signed(false),_gradeS(sign_grade),_gradeE(current_grade){
    std::cout << "called parametric form constructor\n";
    if (sign_grade < 1 || current_grade < 1)
        throw(GradeTooHighException());
    else if (sign_grade > 150 || current_grade > 150)
        throw(GradeTooLowException());
}

std::string Form::getName()const{
    return (this->_Name);
}

bool Form::getSign()const{
    return (this->_signed);
}

int Form::getSignGrade()const{
    return (this->_gradeS);
}

int Form::getExecGrade()const{
    return (this->_gradeE);
}

void Form::beSigned(Bureaucrat& bureau){
    bureau.signForm(*this, this->_signed);
	if (bureau.getGrade() > this->_gradeS)	
		throw(GradeTooHighException());
	else
		this->_signed = true;
	return ;
}

const char	*Form::GradeTooLowException::what(void) const throw()
{
	return ("Form's grade is too low");
}

const char	*Form::GradeTooHighException::what(void) const throw()
{
	return ("Form's grade is too high");
}

std::ostream	&operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName()
		<< " has a sign grade of " << form.getSignGrade()
		<< " and a execution grade of " << form.getExecGrade()
		<< ". It is " << (form.getSign() ? "signed" : "unsigned");
	return (out);
}