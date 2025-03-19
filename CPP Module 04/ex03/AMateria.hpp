/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 19:57:55 by octoross          #+#    #+#             */
/*   Updated: 2025/03/19 18:44:39 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP

# define AMATERIA_HPP

# include <iostream>

# define MESSAGES 0

# define RED "\033[0;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[0;36m"
# define MAGENTA "\033[0;35m"

# define BOLD "\x1B[1m"
# define UNDERLINE "\x1B[4m"

# define RESET "\033[0m"

# include "ICharacter.hpp"

class   ICharacter;

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria(void);
        AMateria(std::string const & type);
        AMateria(const AMateria &to_copy);
        AMateria    &operator= (const AMateria &to_copy);
        virtual ~AMateria(void);
    
        std::string const &getType() const;
		
        virtual AMateria*	clone() const = 0;
        virtual void 		use(ICharacter& target) = 0;
};

#endif