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
int checkdead(t_philos *philo)
{
    size_t n =philo->info->time_to_die;
    pthread_mutex_lock(&philo->info->meal_lock);
    if(get_time() - philo->last_meal > n && philo->eating == 0)
    {
        pthread_mutex_unlock(&philo->info->meal_lock);
        return(1);
    }
    pthread_mutex_unlock(&philo->info->meal_lock);
    return 0;
}
int deaddd(t_info *info)
{
    int i=0;
    while(i<info->num_of_philos)
    {
        if(checkdead(&info->philos[i])==1)
        {
            print(&info->philos[i],info,"is dead",info->philos[i].id);
            pthread_mutex_lock(&info->dead_lock);
            info->deadforever = 1;
            pthread_mutex_unlock(&info->dead_lock);
            return 1;
        }
        i++;
    }
    return 0;

}
int all_fed(t_info *info)
{
    int i;
    int full;

    i = 0;
    full=0;
    while(i < info->num_of_philos)
    {
        if(info->philos[i].eaten_meals == info->num_of_meals)
            full++;
        i++;
    }
    if(full == info->num_of_philos)
        return (1);
    return(0);
}
int not_hungry(t_philos *philo)
{
    pthread_mutex_lock(&philo->info->meal_lock);
    if(philo->eaten_meals == philo->info->num_of_meals)
    {
        // printf("num of meals %d\n",philo->info->num_of_meals);
        // printf("eaten meals %d\n",philo->eaten_meals);
        pthread_mutex_unlock(&philo->info->meal_lock);
        return(1);
    }
    pthread_mutex_unlock(&philo->info->meal_lock);
    return (0);
}
void print(t_philos *philo,t_info *info,char *msg,int id)
{
    pthread_mutex_lock(&philo->info->write_lock);
    size_t time;
    time = get_time() - philo->birthdate;
    if(!info->deadforever)
    {
        printf("%ld %d %s\n",time,id,msg);
    }
    pthread_mutex_unlock(&philo->info->write_lock);
    
}