/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:30 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/30 16:33:18 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span():_max(0){}

Span::Span(const Span& copy){
    *this = copy;
}

Span& Span::operator=(const Span& copy){
    this->_max = copy._max;
    this->_array = copy._array;
    return (*this);
}

Span::~Span(){}

Span::Span(unsigned int N):_max(N){}

void Span::addNumber(unsigned int i){
    if (_array.size() >= _max)
        throw(SpanFull());
    else
        _array.push_back(i);
}

int Span::shortestSpan(void)const{
    if (_array.size() <= 1)
        throw(NoSpan());
    int i = abs(_array[0] - _array[1]);
    for (unsigned int x = 0; x < _array.size() - 1; x++)
    {
        for(unsigned int y = 0; y < _array.size(); y++)
            if (i > abs(_array[x] - _array[y]) && abs(_array[x] - _array[y]) != 0)
                i = abs(_array[x] - _array[y]);
    }
    
    return (i);
}

int Span::longestSpan(void)const{
    if (_array.size() <= 1)
        throw(NoSpan());
    int i = abs(_array[0] - _array[1]);
    for (unsigned int x = 0; x < _array.size() - 1; x++)
    {
        for(unsigned int y = 0; y < _array.size(); y++)
            if (i < abs(_array[x] - _array[y]) && abs(_array[x] - _array[y]) != 0)
                i = abs(_array[x] - _array[y]);
    }
    return (i);
}

const char* Span::SpanFull::what(void)const throw(){
    return("storage already full!");
}

const char* Span::NoSpan::what(void)const throw(){
    return("no span found!");
}