/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:19:44 by nagha             #+#    #+#             */
/*   Updated: 2025/01/22 17:50:11 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int handle_esc(int keycode, t_data *data)
 {
    if (keycode == 65307)
    {
        mlx_destroy_window(data->mlx, data->window);
        mlx_destroy_display(data->mlx);
		printf("x=%d\n",data->x);
		printf("y=%d\n",data->y);
        exit(0);
    }
    return (0);
 }

 int handle_cross(t_data *data)
 {
    mlx_destroy_window(data->mlx, data->window);
    mlx_destroy_display(data->mlx);
    exit(0);
    return (0);
 }
 void ini(t_data *info)
 {
	info->mlx = NULL;
	info->window = NULL;
	info->valid = NULL;
	info->x = 0;
	info->y = 0;
	info->map = NULL;
	info->butcher = NULL;
	info->deadman = NULL;
	info->shark = NULL;
	info->tile = NULL;
	info->volcano = NULL;
	info->width = 0;
	info->hight = 0;
	info->coll = 0;
	info->coff = NULL;
	info->ex = 0;
	info->ey = 0;
	info->p=0;
	info->e=0;
	info->c=0;
	info->copy_c=0;
	info->exit_flag = 0;
 }
void	ft_exit(int flag,char **str)
{
	int	i;

	i = 0;
	if (flag == 1 || flag == 0)
	{
		if (flag == 1)
			ft_putstr("Error\n");
		exit(1);
	}
	else
	{
		if (str)
		{
			while (str[i])
				free(str[i++]);
			free(str);
		}
		if (flag == 2)
			ft_putstr("Error\n");
		if (flag == 3)
			exit(0);
		exit(1);
	}
}
