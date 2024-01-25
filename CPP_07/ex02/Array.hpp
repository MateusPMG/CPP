/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 12:52:40 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/25 14:12:59 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <class T>
class Array{
    private:
        T *_array;
        unsigned int _length;
    public:
        Array();
        Array(const Array& copy);
        Array& operator=(const Array& copy);
        Array& operator=(const Array& copy )const;
        ~Array();
        Array(unsigned int n);
        T& operator[](unsigned int idx);
        const T &operator[](unsigned int i) const;
        unsigned int size(void)const;
};
#include "Array.tpp"