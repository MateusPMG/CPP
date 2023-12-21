/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:34:57 by mpatrao           #+#    #+#             */
/*   Updated: 2023/12/21 15:01:06 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ICharacter.hpp"

class AMateria{
    protected:
        std::string type;
    public:
        AMateria();
        AMateria(std::string const & type);
        AMateria(const AMateria& copy);
        AMateria& operator=(const AMateria& copy);
        ~AMateria();
        std::string const & getType()const;
        void                setType(std::string const & type);
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};