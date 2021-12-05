/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:31 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/05 15:51:44 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <Contact.hpp>

class Phonebook
{
	private:
		static const unsigned int max_num_ = 8;
		Contact	contact_[max_num_];
		int		now_index_;
		bool	is_full_;

	public:
		Phonebook();
		~Phonebook();

		static void	showCommandHeader();
		void		addContact();
		void		setNowIndex();
		void		showIndexItem(int last_index);
		void		searchPhonebook();
		void		showHeader();
		int			exitPhonebook();
		void		invalidInput();
};

#endif
