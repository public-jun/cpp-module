/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 12:53:12 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/10 13:16:48by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "address in memory" << std::endl;
	std::cout << "string   :" << std::hex << &str <<std::endl;
	std::cout << "stringPTR:" << std::hex << stringPTR <<std::endl;
	std::cout << "stringREF:" << std::hex << &stringREF <<std::endl;

	std::cout << "\n" << "display string" << std::endl;
	std::cout << "stringPTR:" << *stringPTR <<std::endl;
	std::cout << "stringREF:" << stringREF <<std::endl;

	return (0);
}
