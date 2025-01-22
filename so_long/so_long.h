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
	void *coff;
	int ex;
	int ey;
	char **cmap;
	int copy_c;
	int exit_flag;
	int p;
	int e;
	int c;
 } t_data;

int handle_esc(int keycode, t_data *data);
int handle_cross(t_data *data);
int checkrec(t_data *info);
int checkborder(t_data *info);
int check_input(t_data *info);
char **inserttoarr(t_data *info,char *file);
void put_image(t_data *info);
void find_xy(t_data *info);
void moveup(t_data *info,int ox,int oy);
void movedown(t_data *info,int ox,int oy);
void moveright(t_data *info,int ox, int oy);
void moveleft(t_data *info,int ox, int oy);
int move(int keycode,t_data *info);
void find_c(t_data *info);
void find_e(t_data *info);
int checkfile(char *file);
void ini(t_data *info);
void insert_copy(t_data *info);
void        flood_fill(t_data *info,int x,int y);
int        solveable(t_data *info);
void	ft_exit(int flag, char **str);
void	ft_exit(int flag, char **str);
#endif
