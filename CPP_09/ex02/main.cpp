/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:43:24 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/07 18:25:23 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
    if (ac == 1)
        std::cout << "Error: provide ints\n";
    else
    {
        std::vector<int> vec;
        std::list<int> lst;
        for (int i = 1; i < ac; ++i)
        {
            int num = std::atoi(av[i]);
            vec.push_back(num);
            lst.push_back(num);
        }
        try
        {
            MergeInsertSort< std::vector<int> > sorter1(vec);
            sorter1.printBefore(vec);
            sorter1.parse();
            sorter1.printAfter(vec);
            std::cout << "Time to process a range of" << sorter1.getNB() << "elements with std::vector : "
            << sorter1.getTime();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        try
        {
            MergeInsertSort< std::list<int> > sorter2;
            sorter2.parse();
            std::cout << "Time to process a range of" << sorter2.getNB() << "elements with std::list : "
            << sorter2.getTime();
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
}