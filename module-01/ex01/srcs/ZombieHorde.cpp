/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:33:47 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/10 18:27:10 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zombies;

	try
	{
		zombies = new Zombie[N];
	}
	catch (std::exception)
	{
		std::cout << "bad alloc" << std::endl;
		exit(1);
	}
	for(int i = 0; i < N; i++)
		zombies[i].set_name(name);
	return(zombies);
}
