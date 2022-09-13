#include "../include/philo.h"

void	*life_of_philosophers(void *program)
{
	unsigned int	i;
	t_node			*node;
	t_data			*data;
	t_philo			*philo;
	pthread_t		death;

	i = 0;
	node = program;
	data = node->data;
	philo = node->philo;
	while (!data->die && i < data->number_meals)
	{
		// pthread_detach(death);
		// pthread_create(&death, NULL, &reaper, node);
		philo_take_fork(node, philo);
		// philo_eat(node, philo);
		// philo_sleep(node, philo);
		// philo_think(node, philo);
		i++;
	}
	// pthread_detach(death);
	// if (data->meals && i == data->number_meals)
	// 	data->meals_finish++;
	return (0);
}

int start_meals(t_node *program, t_data *data, t_philo *philo)
{
	unsigned int	i;

	i = 0;
	data->time = get_time();
	while (i < data->n_philo)
	{
		program[i].philo = &philo[i];
		program[i].data = data;
		if (pthread_create(&philo[i].thread, NULL, &life_of_philosophers,
			&program[i]))
			return (1);
		usleep(10);
		i++;
	}
	return (0);
}

int main(int ac, char **av)
{
    t_data  *data;
    t_philo *philo;
    t_node  *program;

    if (!(data = (t_data *)malloc(sizeof(t_data))))
		return (ft_error(MALLOC_DATA_ERROR));
    if (!init_data(ac, av, data))
        return (FAIL);
    if (!(philo = (t_philo *)malloc(sizeof(t_philo) * data->n_philo)))
		return (ft_error(MALLOC_DATA_ERROR));
	if (!(init_philosopher(data->n_philo, philo)))
        return (FAIL);
	if (!(program = (t_node *)malloc(sizeof(t_node) * (data->n_philo + 1))))
		return (0);
	start_meals(program, data, philo);
	// ft_monitor(data, philo);
	// free (program);
    system("leaks philo");
    return (0);
}

// print_thread(program);
// print_all_param(data, av);
// print_mutex(philo, data);
// 시간 longlong
// 숫자가 아닐때