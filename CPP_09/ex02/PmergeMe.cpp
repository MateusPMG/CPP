/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 12:43:53 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/07 18:03:47 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
MergeInsertSort<T>::MergeInsertSort():_data(void),_time(0),_nbele(0){}

template<typename T>
MergeInsertSort<T>::MergeInsertSort(const MergeInsertSort& copy){
    this->_data = copy._data;
    this->_time = copy._time;
}

template<typename T>
MergeInsertSort<T>& MergeInsertSort<T>::operator=(const MergeInsertSort& copy){
    this->_data = copy._data;
    this->_time = copy._time;
    return (*this);
}

template<typename T>
MergeInsertSort<T>::~MergeInsertSort(){}

template<typename T>
MergeInsertSort<T>::MergeInsertSort(const T& data):_data(data),_time(0),_nbele(0){}

template<typename T>
void MergeInsertSort<T>::parse(T& data){
    clock_t start = clock();
    if (!checkInput(data))
        throw(std::runtime_error("Duplicates or negative numbers found"));
    sort(data);
    clock_t end = clock();
    _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000;
}

template<typename T>
void MergeInsertSort<T>::printBefore(const T& data){
    typename T::const_iterator it;
    std::cout << "Before: ";
    for (it = data.begin(); it != data.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
bool MergeInsertSort<T>::checkInput(const T& data){
    typename T::const_iterator it1, it2;
    for (it1 = data.begin(); it1 != data.end(); it1++){
        if (*it1 < 0)
            return (false);
        for (it2 = data.begin(); it2 != it1; ++it2){
            if (*it1 == *it2)
                return (false);
        }
        _nbele++;
    }
    return (true);
}

template<typename T>
void MergeInsertSort<T>::sort(T& data){
    if (data.size() <= 1)
        return ;
    T left;
    T right;
    typename T::iterator it = data.begin();
    int size = data.size();
    for(int i = 0; i < size / 2; i++){
        left.push_back(*it);
        it++;
    }
    for(int i = size /2; i < size; ++i){
        right.push_back(*it);
        it++;
    }
    sort(left);
    sort(right);
    data.clear();
    typename T::iterator lit = left.begin(), rit = right.begin();
    while (lit != left.end() && rit != right.end()){
        if (*lit < *rit){
            data.push_back(*lit);
            lit++;
        }
        else{
            data.push_back(*rit);
            rit++;
        }
    }
    while (lit != left.end()){
        data.push_back(*lit);
        lit++;
    }
    while (rit != right.end()){
        data.push_back(*rit);
        rit++;
    }
}

template<typename T>
void MergeInsertSort<T>::printAfter(const T& data){
    typename T::const_iterator it;
    std::cout << "After: ";
    for (it = data.begin(); it != data.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename T>
int MergeInsertSort<T>::getNB(){
    return (_nbele);
}

template <typename T>
double MergeInsertSort<T>::getTime(){
    return (_time);
}