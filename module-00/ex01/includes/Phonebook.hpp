/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:31 by jnakahod          #+#    #+#             */
/*   Updated: 2021/12/04 12:31:02 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define MAX_NUM 8

#include <iostream>
#include <string>
#include <Contact.hpp>

class Phonebook
{
	private:
		Contact	contact_[MAX_NUM];
		int		now_index_;
		bool	is_full_;

	public:
		Phonebook();
		~Phonebook();

		static void	showCommandHeader();
		void		addContact();
		void		setNowIndex();
		void		searchPhonebook();
		void		showHeader();
		int			exitPhonebook();
		void		invalidInput();
};

#endif
