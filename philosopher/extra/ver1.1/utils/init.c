#include "../include/philo.h"


int	init_mutex_display(t_philo *philo, int n_philo)
{
	int					i;
	pthread_mutex_t		*display;

	i = 0;
	if (!(display = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t))))
		return (ft_error(MALLOC_DATA_ERROR));
	if (pthread_mutex_init(display, NULL))
		return (FAIL);
	while (i < n_philo)
	{
		philo[i].m_display = display;
		i++;
	}
	return (SUCCESS);
}

int	init_mutex_fork(t_philo *philo, int n_philo)
{
	int i;

	i = 0;
	while (i < n_philo)
	{
		philo[i].m_fork1 = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
		if (philo[i].m_fork1 == NULL)
			return (ft_error(MALLOC_DATA_ERROR));
		if(pthread_mutex_init(philo[i].m_fork1, NULL))
			return (FAIL);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (i == n_philo - 1)
			philo[i].m_fork2 = philo[0].m_fork1;
		else
			philo[i].m_fork2 = philo[i + 1].m_fork1;
		i++;
	}
	return (SUCCESS);
}

int	init_philosopher(unsigned int n_philo, t_philo *philo)
{
	unsigned int i;

	i = 0;
	if(!(init_mutex_fork(philo, n_philo)))
		return (FAIL);
	if(!(init_mutex_display(philo, n_philo)))
		return (FAIL);
	while (i < n_philo)
	{
		philo[i].id = i + 1;
		philo[i].is_dead = 0;
		// philo[i].last_meal = 0;
		i++;
	}
	return (TRUE);
}

void	store_data(int ac, char **av, t_data *data)
{
	data->n_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	data->meal_finish = 0;
	if (ac == 6)
		data->number_meals = ft_atoi(av[5]);
	else
		data->number_meals = -1;
}

int	init_data(int ac, char **av, t_data *data)
{
	// data->option = FALSE;
	if (!check_argu(ac, av) || !check_digit(ac, av) || !check_argu_data(av))
		return(FAIL);
	store_data(ac, av, data);
	data->die = FALSE;
	return (SUCCESS);
}