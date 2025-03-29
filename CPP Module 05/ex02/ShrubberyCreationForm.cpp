/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 16:18:31 by octoross          #+#    #+#             */
/*   Updated: 2025/03/29 20:55:18 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("Shrubbery Creation Form", 25, 5), _target("unknow") {}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target): AForm("Shrubbery Creation Form", 25, 5), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &to_copy): AForm(to_copy), _target(to_copy._target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator= (const ShrubberyCreationForm &to_copy)
{
	if (&to_copy == this)
		return (*this);
	AForm::operator=(to_copy);
	_target = to_copy._target;
	return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm(void) {}


bool	ft_entry_is_dir(struct dirent *entry)
{
	struct stat	file_stat;

	if (entry->d_type == DT_UNKNOWN)
	{
		if (lstat(entry->d_name, &file_stat) == 0)
			return (S_ISDIR(file_stat.st_mode));
		else
			return (false);
	}
	else
		return (entry->d_type == DT_DIR);
}

void	write_entry(std::string entry_name, std::ofstream &outfile, bool is_dir, int depth, bool is_last)
{
	int i = 0;
	while (i < depth + 1)
	{
		if ((i == depth))
		{
			if (is_last)
				outfile << "└── ";
			else
				outfile << "├── ";
		}
		else
			outfile << "│   ";
		i ++;
	}

	if (is_dir)
		outfile << BGGREEN << entry_name << RESET << std::endl;
	else
		outfile << BGREEN << entry_name << RESET << std::endl;
}

void write_dir_tree(const std::string path, std::ofstream &outfile, int depth, int *nbr_dir, int *nbr_files)
{
    struct dirent *entry;
    DIR *dir = opendir(path.c_str());
    if (dir == NULL)
	{
		outfile << path << " [error opening dir]" << std::endl;
        return ;
	}
	(*nbr_dir) ++;
	if (depth == 0)
		outfile << BGGREEN << path << RESET << std::endl;
	
	entry = readdir(dir);
    while (entry != NULL)
	{
		bool is_dir = ft_entry_is_dir(entry);
		struct dirent *next_entry = readdir(dir);

		if (!strcmp(entry->d_name, "..") || !strcmp(entry->d_name, "."))
		{
			entry = next_entry;
			continue ;
		}
		
		write_entry(entry->d_name, outfile, is_dir, depth, (next_entry == NULL));
		if (is_dir)
			write_dir_tree(path + "/" + entry->d_name, outfile, depth + 1, nbr_dir, nbr_files);
		else
			(*nbr_files)++;
		entry = next_entry;
    }
    closedir(dir);
}

void	write_ascii_tree(const std::string path)
{
	std::ofstream	outfile;
		
	outfile.open((std::string(path) + "_shrubbery").c_str());
	if (!outfile)
		return ;

	int nbr_dir = 0;
	int nbr_files = 0;
	write_dir_tree(path, outfile, 0, &nbr_dir, &nbr_files);
	outfile << std::endl << nbr_dir << " directories, " << nbr_files << " files" << std::endl;
	outfile.close();
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	try
	{
		checkExecutionRights(executor);
		write_ascii_tree(_target);
	}
	catch (std::exception &e)
	{
		throw ;
	}
}
