/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:50:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 15:47:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Karen.hpp>

size_t	get_level(std::string input)
{
	std::string level_array[4] =
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};

	size_t	level;
	for (level = 0; level < LEVEL_NUM; level++)
	{
		if (level_array[level] == input)
			break;
	}
	return (level);
}

void	print_log(std::string log)
{
	Karen karen;

	std::cout << "[ " << log << " ]" << std::endl;
	karen.complain(log);
	std::cout << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Log level required" << std::endl;
		std::exit(1);
	}

	std::string input = av[1];
	size_t level = get_level(input);
	switch (level)
	{
	case DEBUG:
		print_log("DEBUG");
	case INFO:
		print_log("INFO");
	case WARNING:
		print_log("WARNING");
	case ERROR:
		print_log("ERROR");
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return (0);
}
