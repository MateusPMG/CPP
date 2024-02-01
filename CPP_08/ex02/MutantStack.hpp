/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:10:48 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/01 16:39:42 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>
#include <algorithm>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(const MutantStack<T> &copy);
		~MutantStack();
		MutantStack<T>	&operator=(const MutantStack<T> &copy);
		typedef typename std::deque<T>::iterator iterator;
		iterator begin();
		iterator end();
};

#include "MutantStack.tpp"