/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:43:40 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/07 18:41:56 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <list>
#include <ctime>
#include <algorithm>
#include <iostream>
//#include "PmergeMe.cpp"

template<typename T>
class MergeInsertSort{
    private:
        T _data;
        double _time;
        int _nbele;
        
    public:
        //mandatory canonical form
        MergeInsertSort();
        MergeInsertSort(const MergeInsertSort& copy);
        MergeInsertSort& operator=(const MergeInsertSort& copy);
        ~MergeInsertSort();
        //mine
        MergeInsertSort(const T& data);
        void parse();
        void checkInput();
        void sort(T& data);
        void printBefore();
        void printAfter();
        int getNB();
        double getTime();
};

#include "PmergeMe.tpp"