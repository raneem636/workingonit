#ifndef PHILO_H
 #define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>

# define PHILO_MAX 202

typedef struct s_philos
{
    pthread_t thread;

    int id;
	int eating;
    int eaten_meals;
	size_t last_meal;
    int dead_flag;
	pthread_mutex_t *rfork;
	pthread_mutex_t *lfork;
    pthread_mutex_t *eat_lock;
    pthread_mutex_t *meal_lock;
    pthread_mutex_t *write_lock;
    pthread_mutex_t *dead_lock;
	struct s_info *info;

} t_philos;

typedef struct s_info
{

    int num_of_philos;
    size_t time_to_die;
    int time_to_eat;
    int time_to_sleap;
    int num_of_meals;

     pthread_mutex_t eat_lock;
    pthread_mutex_t meal_lock;
    pthread_mutex_t write_lock;
    pthread_mutex_t dead_lock;
	pthread_mutex_t forks[PHILO_MAX];
	t_philos philos[PHILO_MAX];

} t_info;

//checking
int checkdegit(char *str);
int     ft_atoi(const char *nptr);
int checkargs(char **v);
int ft_strlen(char *str);

//utils
int	ft_usleep(size_t ms);
void print(t_philos *philo,t_info *info,char *msg,int id);
size_t	get_time(void);
int checkdead(t_philos *philo,struct s_info *info);

//routine
void thinking (t_philos *philo);
void sleaping(t_philos *philo,t_info *info);
void eating(t_philos *philo,struct s_info *info);

//initilaizing
void ini(t_info *philo, char **v);
int intforks(pthread_mutex_t *forks,t_info *info);
void initphilo(t_info *info,t_philos *philo);
void init_info(t_info *info,t_philos *philo);

//creating
void *routine();
int deadforever(t_info *info);
void ft_free(t_philos *philo);
int create_threads(t_info *info,t_philos *philo);
#endif
