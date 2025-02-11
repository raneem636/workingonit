#include "philo.h"

void *routine(void *pointer)
{
    t_philos *philo;

    philo = (t_philos *)pointer;
    if(philo->id % 2 == 0)
        usleep(500);

    while(1)
    {
        thinking(philo);
        eating(philo,philo->info);
        if(deaddd(philo->info)||all_fed(philo->info))
        {
            ft_free(philo->info);
            break;
        }
        sleaping(philo,philo->info);
    }
    return (pointer);
}
void ft_free(t_info *info)
{
    //int i=0;
    // while(i < info->num_of_philos)
    // {
    //     pthread_mutex_destroy(&info->forks[i]);
    //     i++;
    // }
    // while(i < info->num_of_philos)
    // {
    //     pthread_detach(info->philos[i].thread);
    //     i++;
    // }
    pthread_mutex_destroy(&info->eat_lock);
    pthread_mutex_destroy(&info->eat_lock);
    pthread_mutex_destroy(&info->meal_lock);
    pthread_mutex_destroy(&info->dead_lock);
    pthread_mutex_destroy(&info->write_lock);
    pthread_mutex_destroy(&info->eat_lock);
    //exit(0);
}
int create_threads(t_info *info)
{
    int i;

    i = 0;
    
    while (i < info->num_of_philos)
    {
        if(pthread_create(&info->philos[i].thread,NULL,&routine,&info->philos[i])!=0)
             return(1);
        i++;
    }
    i = 0;
    while(i < info->num_of_philos)
    {
        if(pthread_join(info->philos[i].thread,NULL)!= 0)
            return (1);    
        i++;
    }
    return (0);
}