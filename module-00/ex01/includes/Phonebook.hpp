/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 13:49:31 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/09 17:54:18 by jnakahod         ###   ########.fr       */
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
		Contact	contact[MAX_NUM];
		int		now_index;
		bool	is_full;

	public:
		Phonebook();
		~Phonebook();

		void	add_contact();
		void	set_now_index();
		void	search_phonebook();
		void	show_header();
		int		exit_phonebook();
		void	invalid_input();
};

#endif
