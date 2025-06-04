/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: octoross <octoross@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:34:19 by octoross          #+#    #+#             */
/*   Updated: 2025/04/08 18:34:19 by octoross         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
		return (1);
	}
	try 
	{
		Data *d = new Data(typeOfString<int>(argv[1], "int"));

		std::cout << "Initial data address: " << reinterpret_cast<void*>(d) << ", value: " << d->getInt() << std::endl;
		Data *bis = Serializer::deserialize(Serializer::serialize(d));
		std::cout << "Deserialized data address: " << reinterpret_cast<void*>(bis) << ", value: " << bis->getInt() << std::endl;
		
		d->setInt(42);
		
		std::cout << "Initial data value: " << d->getInt() << std::endl;
		std::cout << "Deserialized data value: " << bis->getInt() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}