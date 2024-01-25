/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:26:22 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/25 15:54:34 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <algorithm>

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
    it = std::find(haystack.begin(), haystack.end(), needle1);
    if (it != haystack.end())
        return (it);
    else
        throw(NotFound());
}