#include "so_long.h"

int checkrec(char **map)
{
	int hight=0;
	int width=(int)ft_strlen(map[0]);
	//printf("%i\n",width);
	while(map[hight])
	{
		//printf("%ld\n",strlen(map[hight]));
		if((int)ft_strlen(map[hight])!=width)
			return 0;
		hight++;
	}
	return 1;
}

int checkborder(char **map)
{
	int i=0;
	int j=0;
	int width=(int)ft_strlen(map[0]);
	while(map[i])
		i++;
	printf("%i\n",i);
	while(j<i)
		if (map[j++][0]!='1')
			return 0;
	j=0;
	while(j<i)
		if(map[j++][width-2]!='1')
			return 0;
	i=0;
	while(i<=(width-2))
		if(map[0][i++]!='1')
			return 0;
	i=0;
	while(i<=(width-2))
		if(map[j-1][i++]!='1')
			return 0;
	return 1;
}
int check_input(char **map)
{
	int i=0;
	int j=0;
	int p=0;
	int e=0;
	int c=0;
	int width=(int)ft_strlen(map[0]);
	while(map[i])
	{
		j=0;
		while(j<=(width-2))
		{
			if(map[i][j]!='1'&&map[i][j]!='0'&&map[i][j]!='E'&&map[i][j]!='P'&&map[i][j]!='C')
				return 0;
			if (map[i][j]=='P')
				p++;
			else if (map[i][j]=='E')
				e++;
			else if (map[i][j]=='C')
				c++;
			j++;
		}
		i++;
	}
	if(p!=1 || e!=1 || c<1)
		return 0;
	return 1;
}
char **inserttoarr(int fd, t_info info)
{
	char **map;
    char *line;
    int i=0;
    int map_size;

	printf("%d\n", info.x);
    line = get_next_line(fd);
    map_size=ft_strlen(line);
    map= (char **)malloc(sizeof(char *)* map_size);
    if(!map)
    {
        printf("memory allocation failed");
        close(fd);
        return 0;
    }
    map[i]=line;
    i+=1;
    while((line = get_next_line(fd)) != NULL)
    {
        map[i]=line;
        i++;
    }
	 int j=0;
    while(j<i)
    {
            write(1,map[j],ft_strlen(map[j]));
            j++;
    }
   write(1,"\n",1);
	return (map);
}


int main ()
{
	t_info info;
	int fd;

	info.x = 7;
	fd = open("text.txt",O_RDONLY);
	if (fd == -1)
    {
        printf("error reading the file\n");
        return 0;
    }
	char **map=inserttoarr(fd, info);

	if(!map)
		printf("error\n");
	else
		printf("successfull\n");
	//checkrec(map);
	printf("%d\n",checkrec(map));
	return (0);
}
