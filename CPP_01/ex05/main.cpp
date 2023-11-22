/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:28:08 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/22 14:48:58 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(void){
	Harl	harl1;
	harl1.complain("DEBUG");
	harl1.complain("INFO");
	harl1.complain("WARNING");
	harl1.complain("ERROR");
	harl1.complain("other");
	return (0);
}