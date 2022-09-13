#include "../include/philo.h"

void    print_thread(t_node *temp)
{
    int i = 0;
    
    while (i < temp->data->n_philo)
    {
        printf("스레드-----------------\n");
        printf("i = %d, philo[%d] tid : %ld\n", i, temp[i].philo->id, (long)temp[i].philo->thread);
        printf("-----------------스레드\n");
        i++;
    }
}

void    print_all_param(t_data *data, char **av)
{
    // int i = 0;
    (void) av;

    printf("가나다라마바사아자차카타파하abcdefghijklmn\n");
    printf("num of philosopher : %d\n", data->n_philo);
    printf("-----------------------\n");
    printf("       time_to_die : %d\n", data->t_die);
    printf("       time_to_eat : %d\n", data->t_eat);
    printf("     time_to_sleep : %d\n", data->t_sleep);
    printf("  max_times_of_eat : %d\n", data->number_meals);
    printf("-----------------------\n");
    
}

void    print_mutex(t_philo *philo, t_data *data)
{
    int i = 0;

    while (i < data->n_philo)
    {
        printf("----------------\n");
        printf("m_fork1[%d] tid : %ld\n", i, (long)philo[i].m_fork1);
        printf("m_fork2[%d] tid : %ld\n", i, (long)philo[i].m_fork2);
        printf("m_display[%d] tid : %ld\n", i, (long)philo[i].m_display);
        printf("----------------\n");
        i++;
    }
}