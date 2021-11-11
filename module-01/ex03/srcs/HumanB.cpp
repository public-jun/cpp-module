/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 15:51:12 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 18:18:37 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <HumanB.hpp>

HumanB::HumanB(std::string name) : weapon_(NULL), name_(name)
{
}

HumanB::~HumanB()
{
}

void HumanB::attack() const
{
	if (this->weapon_)
	{
		std::cout << this->name_
				  << " attakc with his "
				  << this->weapon_->getType() << std::endl;
	}
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon_ = &weapon;
}
