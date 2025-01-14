#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdio.h>
#include "libft.h"
typedef struct data
 {
    void *mlx;
    void *window;
 } t_data;

typedef struct info
 {
    int **valid;
	int x;
	int y;
 } t_info;
 
int handle_esc(int keycode, t_data *data);
int handle_cross(t_data *data);
int checkrec(char **map);
int checkborder(char **map);
int check_input(char **map);
//char **inserttoarr(int fd, t_info info);
#endif
