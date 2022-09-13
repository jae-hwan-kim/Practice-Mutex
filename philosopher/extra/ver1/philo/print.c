#include "philo.h"

void    print_philo(t_all *temp)
{
    printf("----------------\n");
    printf("philo[%d] tid : %ld\n", temp->philos->index, (long)(temp->philos->tid[temp->philos->index]));
    printf("index : %d\n", temp->philos->index);
    printf("state : %ld\n", temp->philos->philo[temp->philos->index]);
    printf("----------------\n");
}

void    print_all_param(t_all *program, char **av)
{
    int i = 0;
    printf("가나다라마바사아자차카타파하abcdefghijklmn\n");
    printf("num of philosopher : %d\n", program->number_of_philo);
    printf("       num of fork : %d\n", program->number_of_fork);
    printf("-----------------------\n");
    printf("       time_to_die : %d\n", program->meal->tt_die);
    printf("       time_to_eat : %d\n", program->meal->tt_eat);
    printf("     time_to_sleep : %d\n", program->meal->tt_sleep);
    printf("  max_times_of_eat : %d\n", program->meal->max_times_of_eat);
    printf("-----------------------\n");
    while (i < philo_atoi(av[1]))
    {
        printf("스레드-----------------\n");
        printf("     philo[%d] tid : %ld\n", i, (long)(program->philos->tid[i]));
        printf("   philo[%d] state : %ld\n", i, program->philos->philo[i]);
        printf("p[%d] times_of_eat : %d\n", i, program->philos->times_of_eat[i]);
        printf("-----------------스레드\n");
        i++;
    }
    // printf("               tid : %d\n", program->philos->index);
    printf("-----------------------\n");
    printf("             mutex : %ld\n", (long)(program->mutex->mutex_lock));
}