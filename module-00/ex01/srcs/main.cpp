/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:21 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 12:54:12 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

int	main()
{
	Phonebook phonebook;

	while (true)
	{
		std::string input;

		Phonebook::showCommandHeader();
		std::cout << "COMMAND> ";
		if (!std::getline(std::cin, input))
			break;
		else if (input == "EXIT")
			return (phonebook.exitPhonebook());
		else if (input == "ADD")
			phonebook.addContact();
		else if (input == "SEARCH")
			phonebook.searchPhonebook();
		else
			phonebook.invalidInput();
	}
	std::cout << "\nCLOSED BOOK, bye" << std::endl;
	return (0);
}
