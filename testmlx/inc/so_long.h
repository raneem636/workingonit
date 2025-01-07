#ifndef SO_LONG_H
#define SO_LONG_H

#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
typedef struct data
 {
    void *mlx;
    void *window;
 } t_data;

int handle_esc(int keycode, t_data *data);
int handle_cross(t_data *data);
#endif