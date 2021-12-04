/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:21 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/09 19:00:26 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

int	main()
{
	Phonebook phonebook;

	while (true)
	{
		std::string input;

		std::cout << "COMMAND> ";
		if (!std::getline(std::cin, input))
			break;
		else if (input == "EXIT")
			return (phonebook.exit_phonebook());
		else if (input == "ADD")
			phonebook.add_contact();
		else if (input == "SEARCH")
			phonebook.search_phonebook();
		else
			phonebook.invalid_input();
	}
	std::cout << "\nCLOSED BOOK" << std::endl;
	return (0);
}
