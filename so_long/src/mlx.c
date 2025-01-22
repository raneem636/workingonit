/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:21:18 by nagha             #+#    #+#             */
/*   Updated: 2025/01/22 17:49:52 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int c, char **v)
{
	t_data info;
	if (c == 2)
	{
		ini(&info);
		if (checkfile(v[1]) == 0)
			ft_exit(1,info.map);
		info.map = inserttoarr(&info,v[1]);
		if(!info.map)
			ft_exit(2,info.map);
		find_e(&info);
		if(checkrec(&info)!=1 || checkborder(&info)!=1 || check_input(&info)!=1)
			ft_exit(2,info.map);
		if(!solveable(&info))
			ft_exit(2,info.map);
		printf("%d\n", solveable(&info));
    	info.mlx = mlx_init();
    	info.window = mlx_new_window(info.mlx,((info.width)) * 40, ((info.hight)*40), "MiniLibX Test Window");
		put_image(&info);
    	mlx_key_hook(info.window, move, &info);
    	mlx_hook(info.window, 17, 0, handle_cross, &info);
    	mlx_loop(info.mlx);
	}
    return 0;
}
