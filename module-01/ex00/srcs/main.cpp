/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:06:16 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/10 11:21:02 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include "Zombie.hpp"

const std::string RAND_NAME[] = {
	"Tanaka",
	"Saito",
	"Kondo",
	"Sato",
	"Watanabe",
	"Aoki",
	"Yamada"};

const int RAND_NAME_SIZE = (sizeof(RAND_NAME) / sizeof(std::string));

int main(void)
{
	std::srand(time(NULL));

	Zombie stackZombie = Zombie("stackZombie");
	stackZombie.announce();

	Zombie *heapZombie = newZombie("heapZombie");
	heapZombie->announce();

	for (int i = 0; i < 42; ++i)
		randomChump(RAND_NAME[rand() % RAND_NAME_SIZE]);

	delete heapZombie;
	return (0);
}
