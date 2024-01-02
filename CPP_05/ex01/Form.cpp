/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 13:43:57 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/02 15:29:57 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form():_gradeS(75),_gradeE(75),_Name("default"){
    std::cout << "called form default constructor\n";
    this->_signed = false;
}

Form::Form(const Form& copy):_gradeS(copy._gradeS),_gradeE(copy._gradeE),_Name(copy._Name),_signed(copy._signed){
    std::cout << "called form copy constructor\n";
}

Form& Form::operator=(const Form& copy):_gradeS(copy._gradeS),_gradeE(copy._gradeE),_Name(copy._Name){
    std::cout << "called form copy assignment\n";
    this->_signed = copy._signed;
    return (*this);
}

Form::~Form(){
    std::cout << "called form destructor\n";
}