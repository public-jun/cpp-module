/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnakahod <jnakahod@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 12:50:24 by jnakahod          #+#    #+#             */
/*   Updated: 2021/11/11 12:51:08 by jnakahod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Karen.hpp>

int	main(void)
{
	Karen karen;

	karen.complain("DEBUG");
	karen.complain("INFO");
	karen.complain("WARNING");
	karen.complain("ERROR");
	karen.complain("HOGE");
	karen.complain("");
	return (0);
}
