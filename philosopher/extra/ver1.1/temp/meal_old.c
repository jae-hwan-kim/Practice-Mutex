#include "philo.h"

// eating을 끝내면
// 포크를 책상에 놓고 sleeping 한다.
// 한 번 일어나면, thinking 을 시작한다.
// 시뮬레이션은 철학자가 굶주려 죽으면 멈춘다.

int leftOf(int id, t_all *program)
{
    int num_of_phlios;

    num_of_phlios = program->number_of_philo;
    return ((id + num_of_phlios - 1) % num_of_phlios);
}

int rightOf(int id, t_all *program)
{
    int num_of_phlios;

    num_of_phlios = program->number_of_philo;
    return ((id + 1) % num_of_phlios);
}

void check_eating(int id, t_all *program)
{
    long            *philo;

    philo = program->philos->philo;
    if (philo[id] == THINKING && philo[leftOf(id, program)] != EATING
    && philo[rightOf(id, program)] != EATING)
        philo[id] = EATING;
}

void    ft_sleep(int id, t_all *program)
{
    int     sleep_time;
    long    *philo;
    // float   timestamp;

    philo = program->philos->philo;
    sleep_time = program->meal->tt_sleep;
    if (philo[id] == SLEEPING)
    {
        // timestamp = time_check(program);
        // printf("[%f 밀리초] %d is sleeping\n", timestamp, id);
        printf("[timestamp] philosopher[%d] is sleeping\n", id);
        usleep(sleep_time * 1000);
        philo[id] = THINKING;
    }
}

void    putdown(int id, t_all *program)
{
    pthread_mutex_t *mutex;
    long       *philo;

    mutex = program->mutex->mutex_lock;
    philo = program->philos->philo;
    pthread_mutex_lock(mutex);
    if (philo[id] == EATING)
    {
        philo[id] = SLEEPING;
        ft_sleep(id, program);
    }
    // check_eating(id, program);
    pthread_mutex_unlock(mutex);
}

void    ft_eat(int id, t_all *program)
{
    int eat_time;
    long       *philo;

    eat_time = program->meal->tt_eat;
    philo = program->philos->philo;
    if (philo[id] == EATING)
    {
        printf("[timestamp] philosopher[%d] is eating\n", id);
        usleep(eat_time * 1000);
    }
}

void    pickup(int id, t_all *program)
{
    pthread_mutex_t *mutex;
    long            *philo;

    mutex = program->mutex->mutex_lock;
    philo = program->philos->philo;
    pthread_mutex_lock(mutex);
    check_eating(id, program);
    pthread_mutex_unlock(mutex);
}

void    ft_think(int id, t_all *program)
{
    long    *philo;
    // float   timestamp;

    philo = program->philos->philo;
    philo[id] = THINKING;
    printf("[timestamp] philosopher[%d] is thinking\n", id);
}

void    *have_a_meal(void *temp)
{
    t_all *program;
    int     id;

    program = (t_all *)temp;
    id = program->philos->index;
    (program->philos->index)++;
    while (1)
    {
        ft_think(id, program);
        pickup(id, program);
        ft_eat(id, program);
        putdown(id, program);
        // time_check(program);
    }
    return (0);
}

void    meal(t_all *program)
{
    int         number;
    int         i;
    t_philos    *philos;

    number = program->number_of_philo;
    philos = program->philos;
    philos->index = 0;
    i = philos->index;
    // 철학자 스레드 생성
    while (i < number)
    {
        if (pthread_create(&(philos->tid[i]), NULL, have_a_meal, (void *)program))
            error(THREAD, "thread");
        while (i + 1 != philos->index)
            ;
        i++;
    }
}

// - timestamp_in_ms X has taken a fork
// - timestamp_in_ms X is eating
// - timestamp_in_ms X is sleeping
// - timestamp_in_ms X is thinking
// - timestamp_in_ms X died

// float    time_check(t_all *program)
// {
//     struct timeval *thread_now;
//     struct timeval *started;
//     float   usec;
 
//     usec = 0;
//     thread_now = (struct timeval *)malloc(sizeof(struct timeval));
//     if (0 == thread_now)
//         error(MALLOC, "timeval\n");
//     started = program->start;
//     gettimeofday(thread_now, NULL);
//     // usec = (thread_now->tv_usec - started->tv_usec) / 1000;
//     usec = (double)(thread_now->tv_sec + thread_now->tv_usec/1000.0)
//     - (double)(started->tv_sec + started->tv_usec/1000.0);
//     free(thread_now);
//     return (usec);
// }