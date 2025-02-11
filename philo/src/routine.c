#include "philo.h"
void thinking (t_philos *philo)
{
    print(philo,philo->info,"is thinking",philo->id);
}
void sleaping(t_philos *philo,t_info *info)
{
    print(philo,info,"is sleeping",philo->id);
    ft_usleep(info->time_to_sleap);
}
void eating(t_philos *philo,struct s_info *info)
{
    pthread_mutex_lock(philo->lfork);
    print(philo,info,"has taken a fork",philo->id);
    if (info->num_of_philos == 1)
	{
		ft_usleep(info->time_to_die + info->time_to_eat);
		pthread_mutex_unlock(philo->lfork);
		return ;
	}
    pthread_mutex_lock(philo->rfork);
    print(philo,info,"has taken a fork",philo->id);
    pthread_mutex_lock(&philo->info->eat_lock);
    philo->eating =1;
    pthread_mutex_unlock(&philo->info->eat_lock);
    print(philo,info,"is eating", philo->id);
    philo->last_meal=get_time();
    pthread_mutex_lock(&philo->info->meal_lock);
    philo->eaten_meals++;
    pthread_mutex_unlock(&philo->info->meal_lock);
    ft_usleep(info->time_to_eat);
    pthread_mutex_lock(&philo->info->eat_lock);
    philo->eating =0;
    pthread_mutex_unlock(&philo->info->eat_lock);
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}
