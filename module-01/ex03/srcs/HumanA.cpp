/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:45:29 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 18:14:27 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <HumanA.hpp>

HumanA::HumanA(std::string name, Weapon &weapon) : weapon_(weapon), name_(name)
{
}

HumanA::~HumanA()
{
}

void HumanA::attack() const
{
	std::cout << this->name_
			  << " attakc with his "
			  << this->weapon_.getType() << std::endl;
}
