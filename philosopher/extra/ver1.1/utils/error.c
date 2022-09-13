#include "../include/philo.h"

void	print_usage(void)
{
    printf("Usage : ./philo ");
	printf("[number_of_philosopher] ");
	printf("[time_to_die] [time_to_eat] [time_to_sleep] ");
	printf("[number_of_time_each_philosophers_must_eat]\n");
}

void    arg_error(int error)
{
	if (error == NOT_ENOUGH_ARG)
        printf("Error : the program needs 5 or 6 arguments.\n");
    else if (error == TOO_MANY_ARG)
        printf("Error : you put too many arguments.\n");
	print_usage();
}

int	ft_error(int error)
{
    if (error == MALLOC_DATA_ERROR)
        printf("Error : fail data malloc.\n");
    if (error == MUTEX_INIT_ERROR)
        printf("Error : fail mutex init.\n");
    if (error == INVALID_VALUE_ERROR)
        printf("ERROR : Invalid arguments.\n");
    if (error == NO_PHILO)
        printf("ERROR : No Philos are there.\n");
    return (FAIL);
}
