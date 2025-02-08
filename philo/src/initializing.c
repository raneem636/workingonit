#include "philo.h"
void ini(t_info *info, char **v)
{
    info->num_of_philos = ft_atoi(v[1]);
    info->time_to_die = ft_atoi(v[2]);
    info->time_to_eat = ft_atoi(v[3]);
    info->time_to_sleap = ft_atoi(v[4]);
    if (v[5])
        info->num_of_meals = ft_atoi(v[5]);
    else
        info->num_of_meals = -1;

	//printf("im in ini\n");
}
int intforks(pthread_mutex_t *forks,t_info *info)
{
	int i;

	i = 0;
	while(i < info->num_of_philos)
	{
		pthread_mutex_init(&forks[i],NULL);
		//printf("im in iniforks\n");
		i++;
	}
	return 0;
}
void initphilo(t_info *info,t_philos *philo)
{
	int i;

	i = 0;
	while(i < info->num_of_philos)
	{
		philo[i].id = i + 1;
		philo[i].eating = 0;
		philo[i].eaten_meals = 0;
		philo[i].last_meal = 0;
		philo[i].dead_flag = 0;
		philo[i].write_lock = &info->write_lock;
		philo[i].dead_lock = &info->dead_lock;
		philo[i].meal_lock = &info->meal_lock;
		philo[i].meal_lock = &info->eat_lock;
		philo[i].lfork = &info->forks[i];
		if (i == 0)
			philo[i].rfork = &info->forks[info->num_of_philos - 1];
		else
			philo[i].rfork = &info->forks[i - 1];
		//printf("im in initphilo\n");
		i++;
	}

}
void init_info(t_info *info,t_philos *philo)
{
	//info->philos = philo;
	(void)philo;
	pthread_mutex_init(&info->write_lock, NULL);
	pthread_mutex_init(&info->dead_lock, NULL);
	pthread_mutex_init(&info->meal_lock, NULL);
	pthread_mutex_init(&info->eat_lock, NULL);
}
