/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:06:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/10 18:23:03 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <climits>
#include "Zombie.hpp"

#define SIZE 10

int main(void)
{
	Zombie	*zombies;

	zombies = zombieHorde(SIZE, "jnakahod");
	for(int i = 0; i < SIZE; i++)
		zombies[i].announce();
	delete[] zombies;

	zombies = zombieHorde(SIZE, "Sato");
	for(int i = 0; i < SIZE; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}
