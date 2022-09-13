#include "../include/philo.h"

int	check_argu_data(char **av)
{
	if (*av[1] == '0')
	{
		ft_error(NO_PHILO);
		return (FAIL);
	}
	return (SUCCESS);
}

int	check_digit(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (av[i + 1])
	{
		j = 0;
		if (av[i + 1][j] != '-' && !ft_isdigit(av[i + 1][j]))
			return (ft_error(INVALID_VALUE_ERROR));
		while (av[i + 1][j])
		{
			if (!ft_isdigit(av[i + 1][j]))
				return (ft_error(INVALID_VALUE_ERROR));
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	check_argu(int ac, char **av)
{
    if (!(ac == 5 || ac == 6))
	{
		if (ac < 5)
			arg_error(NOT_ENOUGH_ARG);
		else
			arg_error(TOO_MANY_ARG);
		return (FALSE);
	}
	return (TRUE);
}