/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:26:22 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/30 15:02:00 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>


template <class T>
int findidx(T haystack, int needle1){
    int i = 0;
    typename T::iterator it;
    for (it = haystack.begin(); it != haystack.end(); it++)
    {
        if (*it == needle1)
            return (i);
        i++;
    }
    return (-1);
}

template <class T>
int easyfind(T haystack, int needle1){
     class NotFound : public std::exception
    {
        public:
            const char	*what(void) const throw(){
                return("didnt find any occurrence");
            };
    };
    typename T::iterator it;
    it = find(haystack.begin(), haystack.end(), needle1);
    if (it != haystack.end())
        return (findidx(haystack, needle1));
    else
    {
        throw(NotFound());
    }
}