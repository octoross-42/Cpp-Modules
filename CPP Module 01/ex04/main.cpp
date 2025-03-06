/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:02:46 by octoross          #+#    #+#             */
/*   Updated: 2025/03/06 12:55:46 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void	sendModifiedLine(std::string line, std::ofstream &outfile, std::string a, std::string b)
{
	std::string::size_type 	find_index = 0;
	std::string::size_type 	old_find = 0;
	
	while ((find_index = line.find(a, find_index)) != std::string::npos)
	{
		outfile << line.substr(old_find, find_index - old_find);
		outfile << b;
		find_index += a.length();
		old_find = find_index;
	}
	if (old_find > 0)
		outfile << line.substr(old_find, line.length() - old_find);
	else	
		outfile << line;
	outfile << std::endl;
}

int	main(int argc, char **argv)
{
	std::ifstream	infile;
	std::ofstream	outfile;
	std::string		line;

	if (argc < 4)
	{
		std::cout << USAGE << std::endl;
		return (1);
	}
	infile.open(argv[1]);
	if (!infile)
	{
		std::cout << "Error: no " << argv[1] << " file of directory" << std::endl;
		return (1);
	}
	outfile.open((std::string(argv[1]) + ".replace").c_str());
	if (!outfile)
	{
		std::cout << "Error: cannot open " << argv[1] << std::endl;
		return (1);
	}
	while (std::getline(infile, line))
		sendModifiedLine(line, outfile, std::string(argv[2]), std::string(argv[3]));
	infile.close();
	outfile.close();
}
