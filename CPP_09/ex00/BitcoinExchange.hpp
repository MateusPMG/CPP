/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:44:38 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/02 14:14:34 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <map>
#include <iostream>
#include <fstream>
#include <sstream>
#include <limits>
#include <iomanip>
#include <stdlib.h>

class BitcoinExchange{
    private:
        std::map<std::string, float> _map;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange& copy);
        ~BitcoinExchange();
        BitcoinExchange& operator=(const BitcoinExchange& copy);
        void getDatabase(std::string path);
        void checkFiles(std::string path);
        int checkLine(std::string line);
        int checkDate(std::string date);
        float checkValue(std::string value);
        bool checkLeap(int year);
        void displayInfo(std::string date, float value);
        std::map<std::string, float>::iterator	getClosest(std::string date);
        void printSpecial(float value);
        void parse(std::string input);
        
};