/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:21:26 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/23 16:24:20 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>
void pos(T &pos){
    std::cout << "array has: " << pos << std::endl;
}


template <typename addr>
void iter(addr *array, unsigned int length, void (*function)(addr &)){
    for (unsigned int i = 0; i < length; i++)
        function(array[i]);
}

template <typename addr>
void iter(const addr *array, unsigned int length, void (*function)(addr &)){
    for (unsigned int i = 0; i < length; i++)
        function(array[i]);
}