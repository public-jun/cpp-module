/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:26:05 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 18:14:22 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include <iostream>
#include <string>
#include <Weapon.hpp>

class HumanA
{
	private:
		Weapon		&weapon_;
		std::string	name_;

	public:
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void	attack() const;
};

#endif
