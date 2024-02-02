/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 11:44:22 by mpatrao           #+#    #+#             */
/*   Updated: 2024/02/02 14:15:46 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy){
    *this = copy;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& copy){
    _map = copy._map;
    return (*this);
}

void BitcoinExchange::getDatabase(std::string path){
    std::ifstream   input(path.c_str());
    std::string line;
    
    if (!input.is_open())
        throw (std::runtime_error("Error: couldnt open file1"));
    getline(input, line);//skips first line of input file
    while (getline(input, line))
    {
        std::istringstream s_line(line);
        std::string date, val;
        getline(s_line, date, ',');
        getline(s_line, val);
        _map[date] = strtof(val.c_str(), NULL);
    }
    input.close();
}

void BitcoinExchange::checkFiles(std::string path){
    std::ifstream input(path.c_str());
    std::string line;
    if (!input.is_open())
        throw(std::runtime_error("Error: couldnt open file2"));
    if (input.peek() == std::ifstream::traits_type::eof())
    {   
        input.close();
        throw(std::runtime_error("Error: file empty"));
    }
    getline(input, line);
    if(line != "date | value")
    {
        input.close();
        throw(std::runtime_error("Error: wrong header"));
    }
    while(getline(input, line))
        checkLine(line);
}

int BitcoinExchange::checkLine(std::string line){
    if (line.empty() || line.length() < 14 || line[10] != ' '
		|| line[11] != '|' || line[12] != ' ' || line[13] == ' ')
	{
		std::cout << "Error: line is empty or has wrong format => "
			<< line << std::endl;
		return 1;
	}

	std::string date = line.substr(0, 10);
	std::string value = line.substr(13, line.length() - 13);
	if (checkDate(date))
		return 1;
	float	f_value = checkValue(value);
	if (f_value == -1)
		return 1;
	displayInfo(date, f_value);
	return 0;
}

int	BitcoinExchange::checkDate(std::string date)
{
	struct tm	time;
	int			year;
	std::string	month;
	int			day;

	if (date[4] != '-' || date[7] != '-' || !isdigit(date[0])
		|| !isdigit(date[1]) || !isdigit(date[2]) || !isdigit(date[3])
		|| !isdigit(date[5]) || !isdigit(date[6]) || !isdigit(date[8])
		|| !isdigit(date[9]) || date[10]
		|| !strptime(date.c_str(), "%Y-%m-%d", &time))
	{
		std::cout << "Error: wrong date or wrong date format => "
			<< date << std::endl;
		return 1;
	}
	year = atoi(date.substr(0, 4).c_str());
	month = date.substr(5, 2);
	day = atoi(date.substr(8, 2).c_str());
	if ((!checkLeap(year) && month == "02" && day > 28)
		|| ((month == "04" || month == "06" || month == "09" || month == "11")
		&& day > 30))
	{
		std::cout << "Error: wrong date or wrong date format => "
			<< date << std::endl;
		return 1;
	}
	return 0;
}

bool	BitcoinExchange::checkLeap(int year)
{
	if (year % 4)
		return false;
	else if (year % 100)
		return true;
	else if (year % 400)
		return false;
	else
		return true;
}

float	BitcoinExchange::checkValue(std::string value)
{
	int	len = value.length();
	int	dot = 0;

	if (value[0] == '-')
	{
		std::cout << "Error: number is negative => " << value << std::endl;
		return -1;
	}
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(value[i]))
		{
			if (value[i] == '.')
			{
				if (dot)
				{
					std::cout << "Error: not a number or bad number format => "
						<< value << std::endl;
					return -1;
				}
				dot = 1;
			}
			else if (value[i] == 'f' && i < len - 1)
			{
				std::cout << "Error: not a number or bad number format => "
					<< value << std::endl;
				return -1;
			}
			else
			{
				std::cout << "Error: not a number or bad number format => "
					<< value << std::endl;
				return -1;
			}
		}
	}

	double	test = strtod(value.c_str(), NULL);

	if (test > 1000)
	{
		std::cout << "Error: number is too large => " << value << std::endl;
		return -1;
	}
	if (test > std::numeric_limits<float>::max()
		|| test < -std::numeric_limits<float>::max())
	{
		std::cout << "Error: number will overflow => " << value << std::endl;
		return -1;
	}
	else if (test > 1000)
	{
		std::cout << "Error: number is too large => " << value << std::endl;
		return -1;
	}
	return static_cast<float>(test);
}

void	BitcoinExchange::displayInfo(std::string date, float value)
{
	std::map<std::string, float>::iterator	it;

	it = _map.find(date);
	if (it == _map.end())
		it = getClosest(date);
	if (it == _map.end())
	{
		std::cout << "Error: could not find closest date to " << date
			<< std::endl;
		return;
	}
	std::cout << date << " => ";
	printSpecial(value);
	std::cout << " = ";
	printSpecial(it->second * value);
	std::cout << std::endl;
	return;
}

std::map<std::string, float>::iterator	BitcoinExchange::getClosest(std::string date)
{
	std::map<std::string, float>::reverse_iterator	rbegin = _map.rbegin();
	std::map<std::string, float>::reverse_iterator	rend = _map.rend();

	for (; rbegin != rend && rbegin->first.compare(date) > 0; rbegin++)
		continue;
	if (rbegin == rend)
		return _map.end();
	return --rbegin.base();
}

void	BitcoinExchange::printSpecial(float value)
{
	if (value != static_cast<int>(value))
	{
		std::cout << std::fixed << std::setprecision(2);
		std::cout << value;		
		std::cout.unsetf(std::ios_base::floatfield);
	}
	else
		std::cout << static_cast<int>(value);
}

void BitcoinExchange::parse(std::string input){
    try
    {
        getDatabase("data.csv");
        checkFiles(input);
    }
    catch(const std::runtime_error& error)
    {
        std::cerr << error.what() << '\n';
    }
    
}