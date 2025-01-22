#include "so_long.h"
void insert_copy(t_data *info)
{
	int i=0;
	int k=0;
	int j=0;
	info->cmap=(char **)malloc(sizeof(char *)* (info->hight+1));
	while(info->map[i])
	{
		k=0;
		info->cmap[i]=(char *)malloc(info->width+1);
		while(k<info->width)
		{
			info->cmap[i][k]=info->map[i][k];
			k++;

		}
		info->cmap[i][info->width+1]='\0';
		i++;
	}
	info->cmap[i]=NULL;
    while(j<i)
    {
            write(1,info->map[j],ft_strlen(info->map[j]));
            j++;
    }
   write(1,"\n",1);
}
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
	info->copy_c = c;

}
void find_e(t_data *info)
{
	int i;
	int j;
	i = 0;
	while(info->map[i])
	{
		j=0;
		while(info->map[i][j])
		{
			if(info->map[i][j] == 'E')
			{
				info->ex=j;
				info->ey=i;
				return ;
			}
			j++;
		}
		i++;
	}
}
