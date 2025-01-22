#include "so_long.h"
void moveup(t_data *info,int ox,int oy)
{
	if(info->map[(info->y)-1][info->x] !='1')
	{
		(info->y)-=1;
		if(info->map[oy][ox] =='E'&& info->coll !=0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->volcano,ox*40,oy*40);
			return;
		}
		if(info->map[info->y][info->x] =='E'&& info->coll ==0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
			mlx_destroy_window(info->mlx, info->window);
        	mlx_destroy_display(info->mlx);
			exit(0);
		}
		if(info->map[info->y][info->x] =='C')
		{
			(info->coll)-=1;
			info->map[info->y][info->x] = '0';
		}
		mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
		mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
	}
}
void movedown(t_data *info,int ox,int oy)
{
	if(info->map[(info->y)+1][info->x]!='1')
	{
		info->y += 1;
		if(info->map[oy][ox] =='E'&& info->coll !=0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->volcano,ox*40,oy*40);
			return;
		}
		if(info->map[info->y][info->x] =='E'&& info->coll ==0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
			mlx_destroy_window(info->mlx, info->window);
        	mlx_destroy_display(info->mlx);
			exit(0);
		}
		if(info->map[info->y][info->x] =='C')
		{
			(info->coll)-=1;
			info->map[info->y][info->x] = '0';
		}
		mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
		mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
	}
}
void moveright(t_data *info,int ox, int oy)
{
	if(info->map[info->y][(info->x)+1]!='1')
	{
		(info->x)+=1;
		if(info->map[oy][ox] =='E'&& info->coll !=0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->volcano,ox*40,oy*40);
			return;
		}
		if(info->map[info->y][info->x] =='E'&& info->coll ==0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
			mlx_destroy_window(info->mlx, info->window);
			mlx_destroy_display(info->mlx);
			exit(0);
		}
		if(info->map[info->y][info->x] =='C')
		{
			(info->coll)-=1;
			info->map[info->y][info->x] = '0';
		}
		mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
		mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
	}
}
void moveleft(t_data *info,int ox, int oy)
{
	if(info->map[info->y][(info->x)-1]!='1')
	{
		(info->x)-=1;
		if(info->map[oy][ox] =='E'&& info->coll !=0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->volcano,ox*40,oy*40);
			return;
		}
		if(info->map[info->y][info->x] =='E'&& info->coll ==0)
		{
			mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
			mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
			mlx_destroy_window(info->mlx, info->window);
    		mlx_destroy_display(info->mlx);
			exit(0);
		}
		if(info->map[info->y][info->x] =='C')
		{
			(info->coll)-=1;
			info->map[info->y][info->x] = '0';
		}
		mlx_put_image_to_window(info ->mlx,info->window,info->butcher,info->x*40,info->y*40);
		mlx_put_image_to_window(info ->mlx,info->window,info->tile,ox*40,oy*40);
	}
}
int move(int keycode,t_data *info)
{
	if (keycode == 119)
		moveup(info,info->x,info->y);
	else if(keycode == 100)
		moveright(info,info->x,info->y);
	else if (keycode == 97)
		moveleft(info,info->x,info->y);
	else if (keycode == 115)
		movedown(info,info->x,info->y);
	else
		handle_esc(keycode,info);
	return 0;
}
