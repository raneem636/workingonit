#include "philo.h"
void ini(t_info *philo, char **v)
{
    philo->num_of_philos = ft_atoi(v[1]);
    philo->time_to_die = ft_atoi(v[2]);
    philo->time_to_eat = ft_atoi(v[3]);
    philo->time_to_sleap = ft_atoi(v[4]);
    if (v[5])
        philo->num_of_meals = ft_atoi(v[5]);
    else
        philo->num_of_meals = -1;
}
void iniphilo(t_info *philo)
{
    int i;

    i=0;
    while (i < philo->num_of_philos)
    {
        philo->philos[i].id = i+1;
        philo->philos[i].eaten_meals = 0;

    }
}
int create()