/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 22:11:23 by octoross          #+#    #+#             */
/*   Updated: 2025/03/05 23:51:39 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WEAPON_HPP

# define WEAPON_HPP

#include <iostream>

class   Weapon
{
    private:
        std::string _type;
    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);
        std::string&  getType(void);
        void    setType(std::string newType);
};

#endif