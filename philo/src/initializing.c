#include "philo.h"

void init_info(t_info *info, char **v)
{
	int	i;

    info->num_of_philos = ft_atoi(v[1]);
    info->time_to_die = ft_atoi(v[2]);
    info->time_to_eat = ft_atoi(v[3]);
    info->time_to_sleap = ft_atoi(v[4]);
	info->deadforever = 0;
	//memset(info->forkcheck,0,PHILO_MAX);
	i = 0;
	while(i < info->num_of_philos)
	{
		pthread_mutex_init(&info->forks[i],NULL);
		i++;
	}
	pthread_mutex_init(&info->write_lock, NULL);
	pthread_mutex_init(&info->dead_lock, NULL);
	pthread_mutex_init(&info->meal_lock, NULL);
	pthread_mutex_init(&info->eat_lock, NULL);
	
    if (v[5])
        info->num_of_meals = ft_atoi(v[5]);
    else
        info->num_of_meals = -1;


}

void initphilo(t_info *info)
{
	int i;

	i = 0;
	while(i < info->num_of_philos)
	{
		info->philos[i].id = i + 1;
		info->philos[i].eating = 0;
		info->philos[i].eaten_meals = 0;
		info->philos[i].birthdate = get_time();
		info->philos[i].last_meal = get_time();
		info->philos[i].lfork = &info->forks[i];
		if (i == 0)
			info->philos[i].rfork = &info->forks[info->num_of_philos - 1];
		else
			info->philos[i].rfork = &info->forks[i - 1];
		info->philos[i].info = info;
		i++;
	}
}

