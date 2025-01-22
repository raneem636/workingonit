#include "so_long.h"
void find_xy(t_data *info)
{
	int i;
	int j;
	i = 0;
	while(info->map[i])
	{
		j=0;
		while(info->map[i][j])
		{
			if(info->map[i][j] == 'P')
			{
				info->x=j;
				info->y=i;
				return ;
			}
			j++;
		}
		i++;
	}
}
void find_c(t_data *info)
{
	int i;
	int j;
	int c=0;
	i = 0;
	while(info->map[i])
	{
		j=0;
		while(info->map[i][j])
		{
			if(info->map[i][j] == 'C')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	info->coll = c;
}
