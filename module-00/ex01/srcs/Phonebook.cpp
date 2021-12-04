/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:28 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/09 19:01:51 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>

Phonebook::Phonebook()
{
	this->now_index = 0;
	this->is_full = false;
}

Phonebook::~Phonebook()
{
}

void	Phonebook::add_contact()
{
	contact[now_index].set_item(this->now_index);
	this->set_now_index();
}

void	Phonebook::set_now_index()
{
	now_index += 1;
	if (now_index == MAX_NUM)
	{
		is_full = true;
		now_index = 0;
	}
}

void	Phonebook::show_header()
{
	std::cout << '|';
	std::cout << std::setw(10) << "index";
	std::cout << '|';
	std::cout << std::setw(10) << "first name";
	std::cout << '|';
	std::cout << std::setw(10) << "last name";
	std::cout << '|';
	std::cout << std::setw(10) << "nickname";
	std::cout << '|';
	std::cout << std::endl;
}

void	Phonebook::search_phonebook()
{
	this->show_header();

	int last_index;
	if (is_full)
		last_index = MAX_NUM - 1;
	else
		last_index = this->now_index - 1;
	for(int i = 0; i <= last_index; i++)
		this->contact[i].show_items();
}

int	Phonebook::exit_phonebook()
{
	std::cout << "\nCLOSED BOOK" << std::endl;
	return (0);
}

void	Phonebook::invalid_input()
{
	std::cout << "input is discarded" << std::endl;
}
