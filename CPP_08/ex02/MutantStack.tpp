/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:11:02 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/01 17:40:34 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &copy){
    *this = copy;
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &copy){
    std::stack<T>::operator=(copy);
	return *this;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin(){
    return std::stack<T>::c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end(){
     return std::stack<T>::c.end();
}