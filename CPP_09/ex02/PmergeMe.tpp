/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:18:25 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/07 19:23:22 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

template<typename T>
MergeInsertSort<T>::MergeInsertSort():_data(0),_time(0),_nbele(0){}

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
MergeInsertSort<T>::MergeInsertSort(const T& data){
    _data.assign(data.begin(), data.end());
    _time = 0;
    _nbele = 0;
}

template<typename T>
void MergeInsertSort<T>::parse(){
    clock_t start = clock();
    sort(_data);
    clock_t end = clock();
    _time = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
}

template<typename T>
void MergeInsertSort<T>::printBefore(){
    typename T::const_iterator it;
    std::cout << "Before: ";
    for (it = _data.begin(); it != _data.end(); it++){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void MergeInsertSort<T>::checkInput(){
    typename T::const_iterator it1, it2;
    for (it1 = _data.begin(); it1 != _data.end(); it1++){
        if (*it1 < 0)
            throw(std::runtime_error("Error: wrong format or duplicates or negative numbers found"));;
        for (it2 = _data.begin(); it2 != it1; ++it2){
            if (*it1 == *it2)
                throw(std::runtime_error("Error: wrong format or duplicates or negative numbers found"));
        }
        _nbele++;
    }
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
void MergeInsertSort<T>::printAfter(){
    typename T::const_iterator it;
    std::cout << "After: ";
    for (it = _data.begin(); it != _data.end(); it++){
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