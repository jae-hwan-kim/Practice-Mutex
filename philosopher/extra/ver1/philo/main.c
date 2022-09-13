#include "philo.h"

int main(int ac, char **av)
{
    t_all *program;
    struct timeval *thread_start;
    int i = 0;

    program = (t_all *)malloc(sizeof(t_all));
    if (0 == program)
        return (0);
    thread_start = (struct timeval *)malloc(sizeof(struct timeval));
    if (0 == thread_start)
        error(MALLOC, "timeval\n");
    program->start = thread_start;
    gettimeofday(program->start, NULL);
    if (check_param(ac, av))
    {
        init(program, av, ac);
        meal(program);
        while (i < program->number_of_philo)
        {
            pthread_join(program->philos->tid[i], NULL);
            i++;
        }
        print_all_param(program, av);
    }
    // system("leaks philo");
    return (0);
}