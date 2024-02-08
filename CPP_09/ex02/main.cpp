/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:43:24 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/08 14:15:26 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int ac, char **av){
    if (ac == 1)
        std::cout << "Error: provide ints\n";
    else
    {
        clock_t start1 = clock();
        std::vector<int> vec;
        std::list<int> lst;
        for (int i = 1; i < ac; ++i)
        {
            int num = std::atoi(av[i]);
            vec.push_back(num);
            lst.push_back(num);
        }
        MergeInsertSort< std::vector<int> > sorter1(vec);
        MergeInsertSort< std::list<int> > sorter2(lst);
        try
        {
            sorter1.checkInput();
            sorter2.checkInput();
            sorter1.printBefore(1);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            exit(1);
        }
        clock_t end1 = clock() - start1;
        clock_t startv = clock();
        sorter1.parse();
        clock_t endv = clock();
        double timev = static_cast<double>((endv - startv) + end1) / CLOCKS_PER_SEC * 1000000;
        sorter1.printAfter(1);
        std::cout << "Time to process a range of " << sorter1.getNB() << " elements with std::vector : "
        << timev << " microseconds" << std::endl;
        clock_t startl = clock();
        sorter2.parse();
        clock_t endl = clock();
        double time = static_cast<double>((endl - startl) + end1) / CLOCKS_PER_SEC * 1000000;
        std::cout << "Time to process a range of " << sorter2.getNB() << " elements with std::list : "
        << time << " microseconds" << std::endl;
    }
}