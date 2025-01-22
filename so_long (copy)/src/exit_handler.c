/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_handler.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/01 14:19:44 by nagha             #+#    #+#             */
/*   Updated: 2025/01/19 17:01:48 by rabusala         ###   ########.fr       */
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
