/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 12:16:01 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

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

static bool	is_valid_phone_num(std::string phone_num)
{
	int	i = 0;

	while (phone_num[i])
	{
		if (!isdigit(phone_num[i]))
			return (false);
		i += 1;
	}
	return (true);
}

void	Contact::setItem(int index)
{
	this->index_ = index;
	for(int i = FirstName; i <= Secret; i++)
	{
		std::cout << this->field_name_[i] << ">> ";
		std::string input;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\nCLOSED BOOK" << std::endl;
			exit(0);
		}
		else if (!input.length())
		{
			std::cout << "Empty!! can't added" << std::endl;
			i -= 1;
		}
		else if (i == PhoneNum)
		{
			if (!is_valid_phone_num(input))
			{
				std::cout << "Invalid PHONE NUMBER!!" << std::endl;
				i -= 1;
			}
			else
				this->item_[i] = input;
		}
		else
			this->item_[i] = input;
	}
	std::cout << "A CONTACT ADDED!!"<<std::endl;
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
	std::cout << '|';
	std::cout << std::endl;
}
