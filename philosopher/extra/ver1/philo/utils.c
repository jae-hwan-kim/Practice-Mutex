#include "philo.h"

int	philo_atoi(const char *str)
{
	int			i;
	long long	result;

	i = 0;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		if (result > 2147483647)
			return (-1);
		else
			result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result);
}

void	error(int type, char *message)
{
	if (type == 1)
		printf("Error : %s 할당 실패\n", message);
	else if (type == 2)
		printf("Error : %s 생성 실패", message);
	else if (type == 3)
		printf("Error : %s 생성 실패", message);
	exit(1);
}
