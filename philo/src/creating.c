#include "philo.h"

void *routine(void *pointer)
{
    t_philos *philo;

    philo = (t_philos *)pointer;
    if(philo->id % 2)
        ft_usleep(500);

    while(1)
    {
        thinking(philo);
        eating(philo,philo->info);
        sleaping(philo,philo->info);
    }
    return (pointer);
}
int deadforever(t_info *info)
{
    int i;

    i = 0; 
    printf("%d",info->num_of_philos);
    while(i < info->num_of_philos)
    {
        if(info->philos[i].dead_flag == 1)
            return (1);
        i++;
    }
        printf("im in deadforver\n");
    return (0);
}
void ft_free(t_philos *philo)
{
    t_info info;
    int i=0;
    while(i < info.num_of_philos)
    {
        pthread_mutex_destroy(&info.forks[i]);
        i++;
    }
    pthread_mutex_destroy(philo->eat_lock);
    pthread_mutex_destroy(philo->meal_lock);
    pthread_mutex_destroy(philo->dead_lock);
    pthread_mutex_destroy(philo->write_lock);
    exit(0);
}
int create_threads(t_info *info,t_philos *philo)
{
    int i;

    i = 0;
    while (i < info->num_of_philos)
    {
        if(pthread_create(&info->philos[i].thread,NULL,&routine,&info->philos[i])!=0)
            ft_free(philo);
        printf("im in creating\n");
        i++;
    }
    i = 0;
    while(i < info->num_of_philos)
    {
        if(pthread_join(info->philos[i].thread,NULL)!= 0)
            ft_free(philo);
        i++;
    }
    return (0);
}