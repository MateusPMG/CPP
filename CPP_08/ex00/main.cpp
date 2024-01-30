/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:26:14 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/30 15:02:54 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <deque>
#include <list>


int main(void){
    std::vector<int> vctr;
    for (int i = 1; i < 5; i++)
        vctr.push_back(i);
    try
    {
       std::cout << "found at idx: " << ::easyfind(vctr, 4) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	 std::deque<int> dq;
    for (int i = 1; i < 5; i++)
        dq.push_back(i);
    try
    {
       std::cout << "found at idx: " << ::easyfind(dq, 3) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

	 std::list<int> lst;
    for (int i = 1; i < 5; i++)
        lst.push_back(i);
    try
    {
       std::cout << "found at idx: " << ::easyfind(lst, 1) << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
}