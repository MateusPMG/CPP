/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:21:33 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/30 16:28:00 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <vector>
#include <cstdlib>
class Span {
    private:
        unsigned int _max;
        std::vector<int> _array;
    public:
        Span();
        Span(const Span& copy);
        Span& operator=(const Span& copy);
        ~Span();
        Span(unsigned int N);
        void addNumber(unsigned int i);
        int shortestSpan(void)const;
        int longestSpan(void)const;
        class SpanFull : public std::exception
        {
            public:
                const char	*what(void) const throw();
        };
        class NoSpan : public std::exception
        {
            public:
                const char	*what(void) const throw();
        };
};