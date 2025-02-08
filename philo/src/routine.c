#include "philo.h"
void thinking (t_philos *philo)
{
    print(philo,philo->info,"is thinking",philo->id);
    printf("im in thinking\n");
}
void sleaping(t_philos *philo,t_info *info)
{
    print(philo,info,"is sleaping",philo->id);
    ft_usleep(info->time_to_sleap);
}
void eating(t_philos *philo,struct s_info *info)
{
    pthread_mutex_lock(philo->lfork);
    print(philo,info,"has taken a fork",philo->id);
    pthread_mutex_lock(philo->rfork);
    print(philo,info,"has taken another fork",philo->id);
    pthread_mutex_lock(philo->eat_lock);
    philo->eating =1;
    pthread_mutex_unlock(philo->eat_lock);
    print(philo,info,"is eating", philo->id);
    pthread_mutex_lock(philo->meal_lock);
    philo->eaten_meals++;
    pthread_mutex_unlock(philo->meal_lock);
    philo->last_meal=get_time();
    ft_usleep(info->time_to_eat);
    pthread_mutex_lock(philo->eat_lock);
    philo->eating =0;
    pthread_mutex_unlock(philo->eat_lock);
    pthread_mutex_unlock(philo->rfork);
    pthread_mutex_unlock(philo->lfork);
}
