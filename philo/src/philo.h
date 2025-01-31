#ifndef PHILO_H
 #define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <pthread.h>

typedef struct s_info
{
    pthread_t thread;
    int id;
    int num_of_philos;
    int time_to_die;
    int time_to_eat;
    int time_to_sleap;
    int eaten_meals;
    int num_of_meals;
    pthread_mutex_t rfork;
    pthread_mutex_t lfork;
    t_info *philos;
} t_info;
int checkdegit(char *str);
int     ft_atoi(const char *nptr);
int checkargs(char **v);
int ft_strlen(char *str);
#endif