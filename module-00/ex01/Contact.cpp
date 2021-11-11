/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/09 19:04:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

std::string Contact::field_name[5] = {
	"first name",
	"last name",
	"nickname",
	"phone number",
	"darkest secret"
};

Contact::Contact()
{
	for(int i = FirstName; i <= Secret; i++)
		this->item[i] = std::string();
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

void	Contact::set_item(int index)
{
	this->index = index;
	for(int i = FirstName; i <= Secret; i++)
	{
		std::cout << this->field_name[i] << ">> ";
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
				this->item[i] = input;
		}
		else
			this->item[i] = input;
	}
	std::cout << "A CONTACT ADDED!!"<<std::endl;
}

void	Contact::show_omit_item(std::string src)
{
	std::cout << '|';
	if (src.length() > 10)
		std::cout << src.substr(0, 9) << ".";
	else
		std::cout << std::setw(10) << src;

}

void	Contact::show_items()
{
	std::cout << '|';
	std::cout << std::setw(10) << this->index;
	show_omit_item(this->item[FirstName]);
	show_omit_item(this->item[LastName]);
	show_omit_item(this->item[NickName]);
	std::cout << '|';
	std::cout << std::endl;
}
