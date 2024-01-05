/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:08:45 by mpatrao           #+#    #+#             */
/*   Updated: 2024/01/05 15:51:29 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		
	public:

		RobotomyRequestForm();
		RobotomyRequestForm( RobotomyRequestForm& const copy);
		~RobotomyRequestForm();
		RobotomyRequestForm& operator=( RobotomyRequestForm& const copy);
		void executor()const;
};

#endif