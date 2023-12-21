/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:06:25 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 15:15:35 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Ice : public AMateria{
    public:
        Ice();
        Ice(const Ice& copy);
        Ice& operator=(const Ice& copy);
        ~Ice();
        Ice& clone();
};