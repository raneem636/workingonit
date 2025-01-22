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
    int **valid;
	int x;
	int y;
	char **map;
	void *butcher;
	void *deadman;
	void *shark;
	void *tile;
	void *volcano;
	int width;
	int hight;
	int coll;
 } t_data;

int handle_esc(int keycode, t_data *data);
int handle_cross(t_data *data);
int checkrec(t_data *info);
int checkborder(char **map);
int check_input(char **map);
char **inserttoarr(int fd);
void put_image(t_data *info);
void find_xy(t_data *info);
void moveup(t_data *info,int ox,int oy);
void movedown(t_data *info,int ox,int oy);
void moveright(t_data *info,int ox, int oy);
void moveleft(t_data *info,int ox, int oy);
int move(int keycode,t_data *info);
void find_c(t_data *info);
#endif
