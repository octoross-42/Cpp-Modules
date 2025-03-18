/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 15:54:16 by octoross          #+#    #+#             */
/*   Updated: 2025/03/18 17:09:43 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP

# define BRAIN_HPP

#include <iostream>

class   Brain
{
    private:
        std::string _ideas[100];
    public:
        Brain(void);
        Brain(const Brain &to_copy);
        Brain   &operator= (const Brain &to_copy);
        ~Brain(void);

		std::string	getIdea(int i) const;
        void	setIdea(int i, std::string idea);
        void	setIdeas(std::string ideas[100]);
};

#endif