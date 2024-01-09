/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 13:57:01 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 18:11:11 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():_Name("default"),_Grade(150){
    std::cout << "called Bureaucrat default constructor\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy):_Name(copy._Name),_Grade(copy._Grade){
    std::cout << "called Bureaucrat copy constructor\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    std::cout << "called Bureaucrat copy assignment\n";
    this->_Grade = copy._Grade;
    return (*this);
}

Bureaucrat::~Bureaucrat(){
    std::cout << "called Bureaucrat default destructor\n";
}

Bureaucrat::Bureaucrat(std::string name, int grade):_Name(name),_Grade(grade){
    std::cout << "called Bureaucrat parametric constructor\n";
    if (this->_Grade < 1)
        throw(GradeTooHighException());
    else if (this->_Grade > 150)
        throw(GradeTooLowException());
}

std::string Bureaucrat::getName()const{
    return (this->_Name);
}

int Bureaucrat::getGrade()const{
    return (this->_Grade);
}

void Bureaucrat::increment(){
    if (this->_Grade > 1)
        this->_Grade--;
    else if (this->_Grade == 1)
        throw(GradeTooHighException());
}

void Bureaucrat::decrement(){
    if (this->_Grade < 150)
        this->_Grade++;
    else if (this->_Grade == 150)
        throw(GradeTooLowException());
}

void	Bureaucrat::setGrade(int grade)
{
	if (grade > 150)
		throw(GradeTooLowException());
	else if (grade < 1)
		throw(GradeTooHighException());
	this->_Grade = grade;
}

int Bureaucrat::executeForm(AForm const & form)const{
    if (form.getSign() && form.getExecGrade() >= this->_Grade)
	{
		std::cout << this->_Name << " executed " << form.getName() << std::endl;
		return (0);
	}
	else
	{
		std::cout << this->_Name << " could not execute " << form.getName()
			<< ((form.getSign() && form.getExecGrade() < this->_Grade) ?
			" because his grade was too low" : " because it was not signed")
			<< std::endl;
		return (1);
	}
	return (0);
}

const char* Bureaucrat::GradeTooHighException::what(void)const throw(){
    return ("Reached highest grade already or exceeded");
}

const char* Bureaucrat::GradeTooLowException::what(void)const throw(){
    return ("Reached lowest grade already or exceeded");
}

void Bureaucrat::signForm(AForm& frm, bool sign){
    if (!sign && frm.getSignGrade() >= this->_Grade)
		std::cout << this->_Name << " signed " << frm.getName() << std::endl;
	else
		std::cout << this->_Name << " could not sign " << frm.getName()
			<< ((!sign && frm.getSignGrade() < this->_Grade) ?
			" because his grade was too low" : " because it was already signed")
			<< std::endl;
	return ;
}

std::ostream& operator<<(std::ostream &out, const Bureaucrat& bureau){
    return (out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade());
}