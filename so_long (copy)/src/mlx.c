/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:21:18 by nagha             #+#    #+#             */
/*   Updated: 2025/01/21 09:54:45 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(void)
{
	t_data info;
	int fd;

	fd = open("text.txt",O_RDONLY);
	if (fd == -1)
    {
        printf("error reading the file\n");
        return 0;
    }
	info.map = inserttoarr(fd);

	if(!info.map)
		printf("error\n");
	else
		printf("successfull\n");
	
	printf("%d", checkrec(&info));
	find_xy(&info);
	printf("x=%d\n",info.x);
	printf("y=%d\n",info.y);
	find_c(&info);
	printf("%d",info.coll);
    info.mlx = mlx_init();
    info.window = mlx_new_window(info.mlx,(info.width-1) * 40, (info.hight*40), "MiniLibX Test Window");
	put_image(&info);
    mlx_key_hook(info.window, move, &info);
    mlx_hook(info.window, 17, 0, handle_cross, &info);
    mlx_loop(info.mlx);


    return 0;
}
