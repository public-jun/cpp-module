/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/05 16:03:55 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>
#include <color.hpp>

std::string Contact::field_name_[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

Contact::Contact()
{
	for(int i = FirstName; i <= Secret; i++)
		this->item_[i] = std::string();
}

Contact::~Contact()
{
}

void	Contact::setItem(int index)
{
	this->index_ = index;
	for(int i = FirstName; i <= Secret; i++)
	{
		std::cout << this->field_name_[i] << " >> ";
		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nCLOSED BOOK, bye" << std::endl;
			std::exit(1);
		}
		else if (!input.length())
		{
			std::cout << "Empty!! can't added" << std::endl;
			i -= 1;
		}
		else
			this->item_[i] = input;
	}
	std::cout << GREEN <<"A CONTACT ADDED!!\n" << END <<std::endl;
}

void	Contact::showOmitItem(std::string src)
{
	std::cout << '|';
	if (src.length() > 10)
		std::cout << src.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << src;
}

void	Contact::showItems()
{
	std::cout << '|';
	std::cout << std::setw(10) << this->index_;
	showOmitItem(this->item_[FirstName]);
	showOmitItem(this->item_[LastName]);
	showOmitItem(this->item_[NickName]);
	std::cout << "|" << std::endl;
}

void	Contact::showAll()
{
	for (unsigned int i = 0; i <= Secret ;++i)
	{
		std::cout << field_name_[i]
				  << " >>"
				  << item_[i] << std::endl;
	}
	std::cout << std::endl;
}
