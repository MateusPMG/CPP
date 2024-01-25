/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:26:14 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/25 15:53:05 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>

int main(void){
    std::vector<int> vctr;
    for (int i = 0; i < 4; i++)
        vctr.push_back(i);
    try
    {
       std::cout << "found at idx: " << ::easyfind(vctr, 0) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}