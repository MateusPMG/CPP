/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 14:21:15 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/25 13:49:07 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"


int main(void){
    int array[] = {1, 2, 3, 4, 5, 6};
    
    ::iter(array, 6, pos<const int>);
    
    char array2[] = {'a', 'b' , 'c'};

    ::iter(array2, 3, pos<char>);

    std::string array3[] = {"olha", "e assim"};

    ::iter(array3, 2, pos<std::string>);

    float array4[] = {1.0, 2.4, 4.5};

    ::iter(array4, 3, pos<float>);
    
    return (0);
}