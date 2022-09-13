#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# define MALLOC 1
# define MUTEX 2
# define THREAD 3

// ./philo [철학자 수] [죽는 시간] [식사 시간] [자는 시간] [최대 식사 횟수]

typedef enum condition
{
    SLEEPING,
    EATING,
    THINKING,
}   condition;

// 해당 구조체를 통해 n명 철학자를 만들고, 상태 파악
typedef struct  s_philos
{
    pthread_t   *tid;
    long        *philo;
    int         *times_of_eat;
    int         index;
}   t_philos;

typedef struct  s_mutex
{
    pthread_mutex_t *mutex_lock;
}   t_mutex;

typedef struct  s_meal
{
    int tt_die;
    int tt_eat;
    int tt_sleep;
    int max_times_of_eat;
}   t_meal;

typedef struct  s_all
{
    struct timeval *start;
    float       time;
    int         number_of_fork;
    int         number_of_philo;
    t_philos    *philos;
    t_mutex     *mutex;
    t_meal      *meal;
}   t_all;

int     check_param(int ac, char **av);
int     check_ac(int ac);
int     check_av(char **av);

void    print_all_param(t_all *program, char **av);
void    print_philo(t_all *temp);
void    init(t_all *program, char **av, int ac);
void    init_all(t_all *program, char **av);
void    init_meal(t_meal *meal, char **av, int ac);
void    init_mutex(t_mutex *mutex);

void    meal(t_all *program);

int     philo_atoi(const char *str);
void	error(int type,char *message);

#endif
