/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 19:50:33 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 21:11:59 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP

# define ZOMBIE_HPP

# include <iostream>

class Zombie
{
    private:
        std::string _name;
    public:
        Zombie(void);
        Zombie(std::string name);
        ~Zombie(void);
        void    announce(void);
};

Zombie  *newZombie(std::string name);
void  randomChump(std::string name);

#endif