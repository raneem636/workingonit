#include "so_long.h"
void        flood_fill(t_data *info,int x,int y)
{
    if (x < 0 || x > info -> width || y<0 || y>info->hight)
        return;
    if (info->cmap[y][x]=='1')
        return;
    if (info->cmap[y][x]=='C')
        info->copy_c -=1;
    if (info->cmap[y][x]=='E')
        info->exit_flag=1;
    info->cmap[y][x]='1';
    flood_fill(info, x - 1, y);
	flood_fill(info, x + 1, y);
	flood_fill(info, x, y - 1);
	flood_fill(info, x, y + 1);
}
int        solveable(t_data *info)
{
    info->exit_flag=0;
	find_xy(info);
	find_c(info);
	insert_copy(info);
    flood_fill(info,info->x,info->y);
    if(info->copy_c > 0 || info->exit_flag == 0)
        return(0);
    else
        return(1);
}
