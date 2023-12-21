/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:18:07 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 16:01:05 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria{
    public:
        Cure();
        Cure(const Cure& copy);
        Cure& operator=(const Cure& copy);
        ~Cure();
        AMateria* clone()const;
};