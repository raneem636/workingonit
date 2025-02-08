#include "philo.h"

size_t	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}
int	ft_usleep(size_t ms)
{
	size_t	start;

	start = get_time();
	while ((get_time() - start) < ms)
		usleep(500);
	return (0);
}
int checkdead(t_philos *philo,struct s_info *info)
{
    size_t n =info->time_to_die;
    pthread_mutex_lock(philo->meal_lock);
    if(get_time() - philo->last_meal >= n && philo->eating == 0)
    {
        print(philo,info,"is dead",philo->id);
        pthread_mutex_lock(philo->dead_lock);
        philo->dead_flag = 1;
        pthread_mutex_unlock(philo->dead_lock);
    }
    pthread_mutex_unlock(philo->meal_lock);
    return 0;
}
void print(t_philos *philo,t_info *info,char *msg,int id)
{
    pthread_mutex_lock(philo->write_lock);
    if(!deadforever(info))
    {
        printf("im in print\n");
        printf("%ld ,%d ,%s",get_time(),id,msg);
    }
    pthread_mutex_unlock(philo->write_lock);
    
}