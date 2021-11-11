#include <iostream>
#include <string>

void	megaphone(std::string str)
{
	size_t	i = 0;

	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i += 1;
	}
	std::cout << str;
}

int	main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (size_t i = 1; i < (size_t)ac; i++)
	{
		std::string str(av[i]);
		megaphone(str);
	}
	std::cout << std::endl;
}
