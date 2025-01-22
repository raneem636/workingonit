#include "so_long.h"

void put_image(t_data *info)
{
	int x=40;
	int y=40;
	info -> butcher=mlx_xpm_file_to_image(info ->mlx,"ghost.xpm",&x,&y);
	info -> deadman=mlx_xpm_file_to_image(info ->mlx,"vampire.xpm",&x,&y);
	info -> shark=mlx_xpm_file_to_image(info ->mlx,"skullwall.xpm",&x,&y);
	info -> volcano=mlx_xpm_file_to_image(info ->mlx,"skully.xpm",&x,&y);
	info -> tile=mlx_xpm_file_to_image(info ->mlx,"sfloor.xpm",&x,&y);
	int i=0;
	int j;

	while(info->map[i])
	{
		j=0;
		while(info->map[i][j])
		{
			if(info->map[i][j] ==  '1')
				mlx_put_image_to_window(info ->mlx,info->window,info->shark,j*x,i*y);
			else if(info->map[i][j] ==  '0')
				mlx_put_image_to_window(info ->mlx,info->window,info->tile,j*x,i*y);
			else if(info->map[i][j] ==  'E')
				mlx_put_image_to_window(info ->mlx,info->window,info->volcano,j*x,i*y);
			else if(info->map[i][j] ==  'P')
				mlx_put_image_to_window(info ->mlx,info->window,info->butcher,j*x,i*y);
			else if(info->map[i][j] ==  'C')
				mlx_put_image_to_window(info ->mlx,info->window,info->deadman,j*x,i*y);
			j++;
		}
		i++;
	}
}
