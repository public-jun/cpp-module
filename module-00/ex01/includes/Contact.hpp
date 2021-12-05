/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:00:02 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 16:09:30 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	public:
		Contact();
		~Contact();
		void	setItem(int index);
		void	showOmitItem(std::string src);
		void	showItems();
		void	showAll();

	private:
		static std::string	field_name_[5];
		std::string			item_[5];
		int					index_;

		enum Field
		{
			FirstName,
			LastName,
			NickName,
			PhoneNum,
			Secret
		};
};

#endif
