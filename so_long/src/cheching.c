#include "so_long.h"

int checkrec(t_data *info)
{
	int i=0;
	int len=0;
	while(info->map[i])
	{
		len=(int)ft_strlen(info->map[i])-1;
		printf("len = %d\n",len);
		printf("width = %d\n", info->width);
		if(len!=info->width)
			return 0;
		i++;
	}
	return 1;
}

int checkborder(t_data *info)
{
	int i;
	i=0;
	while(i<info->width)
	{
		if(info->map[0][i] != '1' || info->map[(info->hight) - 1][i] != '1')
			return (0);
		i++;
	}
	i=0;
	while(i<info->hight)
	{
		if(info->map[i][0] != '1' || info->map[i][(info->width) - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
int check_input(t_data *info)
{
	int i=0;
	int j;
	while(i<info->hight)
	{
		j=0;
		while(j<info->width)
		{
			if(info->map[i][j]!='1'&&info->map[i][j]!='0'&&info->map[i][j]!='E'&&info->map[i][j]!='P'&&info->map[i][j]!='C')
				return 0;
			if (info->map[i][j]=='P')
				info->p++;
			else if (info->map[i][j]=='E')
				info->e++;
			else if (info->map[i][j]=='C')
				info->c++;
			j++;
		}
		i++;
	}
	if(info->p!=1 || info->e!=1 || info->c<1)
		return 0;
	return 1;
}
char **inserttoarr(t_data *info,char *file)
{
    char *line;
	char **map;
    int i=0;
    int map_size=0;
	int fd;
	fd=open(file,O_RDONLY);
	if (fd == -1)
    {
        printf("error reading the file\n");
        return NULL;
    }
	while((line = get_next_line(fd)) != NULL)
	{
        map_size++;
		free(line);
	}
	close(fd);
    map= (char **)malloc(sizeof(char *)*(map_size+1));
    if(!map)
    {
        printf("memory allocation failed");
		return(NULL);
    }
	fd=open(file,O_RDONLY);
    while((line = get_next_line(fd)) != NULL)
    {
       	map[i]=line;
        i++;
    }
	map[i]=NULL;
	int j=0;
	while(j<i)
	{
		write(1,map[j],ft_strlen(map[j]));
		j++;
	}
	info->hight=i;
	info->width=(int)ft_strlen(map[0])-1;
   return(map);
}

int checkfile(char *file)
{
	int len;

	len = ft_strlen(file);
	if (file[len-1] == 'r' && file[len-2] == 'e' && file[len - 3] == 'b' && file[len - 4] == '.')
		return (1);

	return (0);

}
