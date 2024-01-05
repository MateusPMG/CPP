/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:43:57 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 14:17:56 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm():_Name("default"),_signed(false),_gradeS(75),_gradeE(75){
    std::cout << "called AForm default constructor\n";
}

AForm::AForm(const AForm& copy):_Name(copy._Name),_signed(copy._signed),_gradeS(copy._gradeS),_gradeE(copy._gradeE){
    std::cout << "called AForm copy constructor\n";
}

AForm& AForm::operator=(const AForm& copy){
    std::cout << "called AForm copy assignment\n";
    this->_signed = copy._signed;
    return (*this);
}

AForm::~AForm(){
    std::cout << "called AForm destructor\n";
}

AForm::AForm(std::string name, int sign_grade, int current_grade):_Name(name),_signed(false),_gradeS(sign_grade),_gradeE(current_grade){
    std::cout << "called parametric AForm constructor\n";
    if (sign_grade < 1 || current_grade < 1)
        throw(GradeTooHighException());
    else if (sign_grade > 150 || current_grade > 150)
        throw(GradeTooLowException());
}

std::string AForm::getName()const{
    return (this->_Name);
}

bool AForm::getSign()const{
    return (this->_signed);
}

int AForm::getSignGrade()const{
    return (this->_gradeS);
}

int AForm::getExecGrade()const{
    return (this->_gradeE);
}

void AForm::beSigned(Bureaucrat& bureau){
    bureau.signForm(*this, this->_signed);
	if (bureau.getGrade() > this->_gradeS)	
		throw(GradeTooHighException());
	else
		this->_signed = true;
	return ;
}

const char	*AForm::GradeTooLowException::what(void) const throw()
{
	return ("AForm's grade is too low");
}

const char	*AForm::GradeTooHighException::what(void) const throw()
{
	return ("AForm's grade is too high");
}

std::ostream	&operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName()
		<< " has a sign grade of " << form.getSignGrade()
		<< " and a execution grade of " << form.getExecGrade()
		<< ". It is " << (form.getSign() ? "signed" : "unsigned");
	return (out);
}