/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 14:38:57 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/24 16:10:15 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"


template <class T>
Array<T>::Array():_array(new T[0]), _length(0){}

template <class T>
Array<T>::Array(unsigned int n):_array(new T[n]),_length(n){}

template <class T>
Array<T>::Array(const Array& copy):_array(new T[copy._length]),_length(copy._length){
	for (unsigned int i = 0; i < _length; i++)
		_array[i] = copy._array[i];
}

template <class T>
Array<T>& Array<T>::operator=(const Array& copy)
{
	delete[] _array;
	this->_length = copy._length;
	this->_array = new T[this->_length];
	for (unsigned int i = 0; i < this->_length; i++)
	{
		this->_array[i] = copy._array[i];
	}
	return (*this);
}

template <typename T>
Array<T>::~Array(){
	delete[] this->_array;
}

template <typename T>
T& Array<T>::operator[](unsigned int idx){
	if(!this->_length || idx > this->_length - 1)
		throw(std::exception());
	return(this->_array[idx]);
}

template <typename T>
unsigned int Array<T>::size(void) const
{
	return (this->_length);
}