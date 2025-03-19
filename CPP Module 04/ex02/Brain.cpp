/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:54:05 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 19:13:52 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    int i = 0;
    while (i < 100)
        _ideas[i ++] = "";
}

Brain::Brain(const Brain &to_copy)
{
    if (this == &to_copy)
        return ;

    int i = 0;
    while (i < 100)
    {
        _ideas[i] = to_copy.getIdea(i);
        i ++;
    }
}

Brain   &Brain::operator= (const Brain &to_copy)
{
    if (this == &to_copy)
        return (*this);

    int i = 0;
    while (i < 100)
    {
        _ideas[i] = to_copy.getIdea(i);
        i ++;
    }
    return (*this);
}

Brain::~Brain(void) {}

std::string	Brain::getIdea(int i) const
{
    if ((i < 0) || (i > 99))
        return ("");
    return _ideas[i];
}

void	Brain::setIdea(int i, std::string idea)
{
    if ((i < 0) || (i > 99))
        return ;
    _ideas[i] = idea;
}

void	Brain::setIdeas(std::string ideas[100])
{
    int i = 0;
    while (i < 100)
    {
        _ideas[i] = ideas[i];
        i ++;
    }
}