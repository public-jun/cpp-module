/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:28 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 12:47:22by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Phonebook.hpp>
#include <color.hpp>

Phonebook::Phonebook()
{
	now_index_ = 0;
	is_full_ = false;
}

Phonebook::~Phonebook()
{
}

void	Phonebook::showCommandHeader()
{
	std::cout << "Enter "
			  << BOLD <<"ADD" << END
			  <<","
			  << BOLD <<" SEARCH" << END
			  << " or "
			  << BOLD <<"EXIT" << END
			  << " command" << std::endl;
}

void	Phonebook::addContact()
{
	std::cout << "\nEnter contact's infomation" << std::endl;
	contact_[now_index_].setItem(now_index_);
	setNowIndex();
}

void	Phonebook::setNowIndex()
{
	now_index_ += 1;
	if (now_index_ == MAX_NUM)
	{
		is_full_ = true;
		now_index_ = 0;
	}
}

void	Phonebook::showHeader()
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

void	Phonebook::searchPhonebook()
{
	showHeader();

	int last_index;
	if (is_full_)
		last_index = MAX_NUM - 1;
	else
		last_index = now_index_ - 1;
	for(int i = 0; i <= last_index; i++)
		contact_[i].showItems();
}

int	Phonebook::exitPhonebook()
{
	std::cout << "\nCLOSED BOOK, bye" << std::endl;
	return (0);
}

void	Phonebook::invalidInput()
{
	std::cout << RED
			  << "Input is discarded\n"
			  << END
			  << std::endl;
}
