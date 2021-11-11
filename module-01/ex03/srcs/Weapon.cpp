/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 14:44:36 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 18:13:09 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>

Weapon::Weapon(std::string type) : type_(type)
{
}

Weapon::~Weapon()
{
}

const std::string &Weapon::getType() const
{
	return (this->type_);
}

void Weapon::setType(std::string type)
{
	this->type_ = type;
}
