/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 19:52:08 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/10 22:27:41y jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

static void	print_err_msg(std::string err_msg)
{
	std::cout << err_msg << std::endl;
	std::exit(1);
}

static bool	is_empty_str(char **av)
{
	if (av[2][0] == '\0' || av[3][0] == '\0')
		return (true);
	return (false);
}

void	file_to_buffer(const std::string &file_path, std::string &buffer)
{
	std::ifstream	ifs(file_path);

	if (!ifs)
		print_err_msg("Failed to open file");
	char c;
	while (ifs.get(c))
		buffer += c;
	if (!ifs.eof())
		print_err_msg("Failed to read file");
}

void	ft_replace(const std::string s1, const std::string s2, std::string &buffer)
{
	std::string::size_type pos(0);

	while (true)
	{
		pos = buffer.find(s1, pos);
		if (pos == std::string::npos)
			break;
		buffer.erase(pos, s1.length());
		buffer.insert(pos, s2);
		pos += s2.length();
	}
}

void	buffer_to_file(const std::string file_path, const std::string buffer)
{
	std::ofstream	ofs(file_path);

	if (!ofs)
		print_err_msg("Failed to open file");
	ofs << buffer << std::flush;
	if (!ofs)
		print_err_msg("Failed to write");
}

int	main(int ac, char **av)
{
	if (ac != 4)
		print_err_msg("Three arguments are required");
	if (is_empty_str(av))
		print_err_msg("String is empty");
	std::string file_path = av[1];
	std::string buffer;
	file_to_buffer(file_path, buffer);
	ft_replace(av[2], av[3], buffer);
	file_path += ".replace";
	buffer_to_file(file_path, buffer);
	return (0);
}
