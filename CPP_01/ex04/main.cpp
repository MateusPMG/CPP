/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpatrao <mpatrao@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:12:01 by mpatrao           #+#    #+#             */
/*   Updated: 2023/11/21 17:22:12 by mpatrao          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::ifstream fs;
		fs.open(filename.c_str());
		if (!fs)
		{
			std::cerr << "Error: couldnt open file\n";
			return (1);
		}
		std::string	content;
		std::string line;
		while (std::getline(fs, line))
		{
			content += line;
			if (!fs.eof())
				content += '\n';
		}
		fs.close();
		size_t	pos = 0;
		std::string	s1 = av[2];
		std::string s2 = av[3];
		if (s1.empty())
		{
			std::cerr << "Error: s1 cannot be empty\n";
			return (1);
		}
		while ((pos = content.find(s1, pos)) != std::string::npos)
		{
			content = content.substr(0, pos) + s2 + content.substr(pos + s1.length());
			pos += s2.length();
		}
		std::ofstream newfile;
		newfile.open((filename + ".replace").c_str());
		if (!newfile)
		{
			std::cerr << "Error: couldnt open file .replace \n";
			return (1);
		}
		newfile << content;
		newfile.close();
		std::cout << "Success\n";
	}
	else
	{
		std::cerr << "Error: wrong number of arguments\n"
		<< "Must be: Filename, string 1, string 2\n";
		return (1);
	}
	return (0);
}