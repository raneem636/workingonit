#include "philo.h"
int main(int c, char **v)
{
    //t_philos philo;
    t_info info;
    if (c == 6 || c == 5)
    {
        if (checkargs(v) == 0)
        {
            printf("error\n");
            return 0;
        }
         
        init_info(&info,v);
        printf("main: nb_philos: %d\n", info.num_of_philos);
        initphilo(&info);
        create_threads(&info);
        ft_free(&info);
        
        // ft_free(&philo);
    }
    else
        printf("ERROR: invalid number of arguments\n");
    return 0;
}
