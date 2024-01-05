/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:12:34 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 15:47:43 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
:AForm("ShrubberyCreationForm", 145, 137),_target("office"){}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
:AForm("ShrubberyCreationForm", 145, 137),_target(target){}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& copy)
:AForm("ShrubberyCreationForm", 145, 137),_target(copy._target){}

ShrubberyCreationForm::~ShrubberyCreationForm(){}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm& const copy){
	this->_target = copy._target;
	this->setSign(copy.getSign());
	return (*this);
}

void ShrubberyCreationForm::executor()const{
	std::ofstream Myfile(this->_target + "_shrubbery");
	Myfile << "      /\\n";     
	Myfile << "     /\*\\n";     
	Myfile << "    /\O\*\\n";    
	Myfile << "   /*/\/\/\\n"; 
	Myfile << "  /\O\/\*\/\\n"; 
	Myfile << " /\*\/\*\/\/\\n";
	Myfile << "/\O\/\/*/\/O/\\n";
	Myfile << "      ||\n";     
	Myfile << "      ||\n";     
	Myfile << "      ||\n";
	Myfile << "\n";
	Myfile << "    *\\n";
	Myfile << "   /.\\n";
	Myfile << "  /o..\\n";
	Myfile << "  /..o\\n";
	Myfile << " /.o..o\\n";
	Myfile << " /...o.\\n";
	Myfile << "/..o....\\n";
	Myfile << "^^^[_]^^^\n";
	Myfile.close();
}