/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:30:30 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/01 16:02:26 by mpatrao          ###   ########.fr       */
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
    std::vector<long>	tmp;
	std::vector<long>	diff;
	std::copy(_array.begin(), _array.end(), std::back_inserter(tmp));
	std::sort(tmp.begin(), tmp.end());
	std::adjacent_difference(tmp.begin(), tmp.end(), std::back_inserter(diff));
	return *std::min_element(++diff.begin(), diff.end());
}

int Span::longestSpan(void)const{
    if (_array.size() <= 1)
        throw(NoSpan());
   return (long)*std::max_element(_array.begin(), _array.end())
		- (long)*std::min_element(_array.begin(), _array.end());
}

void Span::manyAdd(std::vector<int>::iterator start, std::vector<int>::iterator end){
    if (_array.size() == _max || std::distance(start, end) > (long)(_max - _array.size()))
        throw(SpanFull());
    else
     this->_array.insert(_array.end(), start, end);
}

const char* Span::SpanFull::what(void)const throw(){
    return("storage already full or NOT enough space!");
}

const char* Span::NoSpan::what(void)const throw(){
    return("no span found!");
}