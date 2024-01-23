/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 13:44:19 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/23 14:19:13 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

template <typename anyType>
anyType max(anyType a, anyType b){
    return (a > b ? a : b);
}

template <typename anyType>
anyType min(anyType a, anyType b){
    return (a < b ? a : b);
}

template <typename anyType>
void swap(anyType& a, anyType& b){
    anyType swp = a;
    a = b;
    b = swp;
}