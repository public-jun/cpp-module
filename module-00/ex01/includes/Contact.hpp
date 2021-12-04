/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 00:00:02 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/09 18:31:46 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include <iomanip>

class Contact
{
	private:
		static std::string	field_name[5];
		std::string			item[5];
		int					index;

		enum Field
		{
			FirstName,
			LastName,
			NickName,
			PhoneNum,
			Secret
		};

	public:
		Contact();
		~Contact();
		void	set_item(int index);
		void	show_items();
		void	show_omit_item(std::string src);
};

#endif
