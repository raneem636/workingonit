#include "philo.h"
int main(int c, char **v)
{
    t_philos philo;
    t_info info;
    if (c == 6 || c == 5)
    {
        if (checkargs(v) == 0)
        {
            printf("error\n");
            return 0;
        }
        ini(&info,v);
        intforks(info.forks,&info);
        init_info(&info,&philo);
        initphilo(&info,&philo);
        create_threads(&info,&philo);
        ft_free(&philo);
    }
    else
        printf("ERROR: invalid number of arguments\n");
    return 0;
}
