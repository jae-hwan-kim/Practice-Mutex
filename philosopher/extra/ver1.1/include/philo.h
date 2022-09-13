#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>

# define MILLESEC	1
# define MICROSEC 	0

# define FORK	"has taken a fork"
# define EAT	"is eating"
# define SLEEP	"is sleeping"
# define THINK	"is thinking"
# define DEAD	"is dead"

typedef enum yesno
{
    FALSE,
	TRUE,
} yesno;

typedef enum successfail
{
    FAIL,
	SUCCESS,
} successfail;

typedef enum error
{
    NOT_ENOUGH_ARG,
	TOO_MANY_ARG,
	MALLOC_DATA_ERROR,
	MUTEX_INIT_ERROR,
	INVALID_VALUE_ERROR,
	NO_PHILO,
} error;

typedef char				t_bool;

typedef	struct				s_node
{
	struct s_data	*data;
	struct s_philo	*philo;
}							t_node;

typedef struct				s_data
{
	unsigned int	n_philo;
	unsigned int	t_die;
	unsigned int	t_eat;
	unsigned int	t_sleep;
	unsigned int	number_meals;
	unsigned int	meal_finish;
	long			time;
	t_bool			die;
}							t_data;

typedef struct				s_philo
{
	pthread_t			thread;
	pthread_mutex_t		*m_fork1;
	pthread_mutex_t		*m_fork2;
	pthread_mutex_t		*m_display;
	unsigned int		id;
	unsigned int		last_meal;
	t_bool				is_dead;
	// t_bool				life;
}							t_philo;

// ./philo [철학자 수] [죽는 시간] [식사 시간] [자는 시간] [최대 식사 횟수]

int		ft_atoi(const char *str);
void	print_usage(void);
void    arg_error(int error);
int		ft_error(int error);
int		init_data(int ac, char **av, t_data *data);
int		init_philosopher(unsigned int n_philo, t_philo *philo);
int		ft_isdigit(int c);

int		check_argu(int ac, char **av);
int		check_digit(int ac, char **av);
int		check_argu_data(char **av);

void	philo_take_fork(t_node *program, t_philo *philo);

void	display(t_node *program, t_philo *philo, char *event);
long	get_time(void);
long	time_diff(int last, long curr);

void    print_all_param(t_data *data, char **av);
void    print_mutex(t_philo *philo, t_data *data);
void    print_thread(t_node *temp);

#endif
