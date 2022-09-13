#include "philo.h"
// ./philo [철학자 수] [죽는 시간] [식사 시간] [자는 시간] [최대 식사 횟수]
void    init_all(t_all *program, char **av)
{
    program->number_of_fork = philo_atoi(av[1]);
    program->number_of_philo = philo_atoi(av[1]);
    program->philos = (t_philos *)malloc(sizeof(t_philos));
    if (0 == program->philos)
        error(MALLOC, "philos");
    program->mutex = (t_mutex *)malloc(sizeof(t_mutex));
    if (0 == program->mutex)
        error(MALLOC, "mutex\n");
    program->meal = (t_meal *)malloc(sizeof(t_meal));
    if (0 == program->meal)
        error(MALLOC, "meal\n");
}

void    init_mutex(t_mutex *mutex)
{
    mutex->mutex_lock = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    if (0 == mutex->mutex_lock)
        error(MALLOC, "mutex\n");
    if (0 != pthread_mutex_init(mutex->mutex_lock, NULL))
        error(MUTEX, "mutex\n");
}

void    init_meal(t_meal *meal, char **av, int ac)
{
    meal->tt_die = philo_atoi(av[2]);
    meal->tt_eat = philo_atoi(av[3]);
    meal->tt_sleep = philo_atoi(av[4]);
    if (ac == 6)    
        meal->max_times_of_eat = philo_atoi(av[5]);
    else
        meal->max_times_of_eat = 0;
}

void    init_philo(t_all *program)
{
    int         number;
    int         i;
    t_philos    *philos;

    number = program->number_of_philo;
    philos = program->philos;
    philos->tid = (pthread_t *)malloc(sizeof(pthread_t) * number);
    if (0 == philos->tid)
        error(MALLOC, "tid\n");
    philos->philo = (long *)malloc(sizeof(long) * number);
    if (0 == philos->philo)
        error(MALLOC, "philo\n");
    philos->times_of_eat = (int *)malloc(sizeof(int) * number);
    if (0 == philos->times_of_eat)
        error(MALLOC, "times_of_eat\n");
    philos->index = 0;
    i = philos->index;
    // 철학자 변수 초가화
    while (i < number)
    {
        program->philos->times_of_eat[i] = 0;
        program->philos->philo[i] = THINKING;
        i++;
    }
}

void    init(t_all *program, char **av, int ac)
{
    init_all(program, av);
    init_mutex(program->mutex);
    init_meal(program->meal, av, ac);
    init_philo(program);
}