#include "philo.h"
int main(int c, char **v)
{
    if (c == 6 || c == 5)
    {
        if (checkargs(v) == 0)
            return 1;
    }
    else
        printf("ERROR: invalid number of arguments\n");
    return 0;
}