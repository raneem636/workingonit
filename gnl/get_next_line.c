/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:22:22 by rabusala          #+#    #+#             */
/*   Updated: 2025/01/14 13:45:36 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	line_length(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*clean(char **array, char *ss)
{
	if (*array)
	{
		free(*array);
		*array = NULL;
	}
	if (ss)
		free(ss);
	return (NULL);
}

char	*read_1ine(int fd, char *array)
{
	char	*buf;
	char	*temp;
	int		bytes_read;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	if (!array)
		array = ft_strdup("");
	bytes_read = read(fd, buf, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buf[bytes_read] = '\0';
		temp = array;
		array = ft_strjoin(array, buf);
		free(temp);
		if (ft_strchr(array, '\n'))
			break ;
		bytes_read = read(fd, buf, BUFFER_SIZE);
	}
	if (bytes_read == -1)
		return (clean(&array, buf));
	free(buf);
	return (array);
}

char	*get_next_line(int fd)
{
	static char	*array = NULL;
	char		*line;
	char		*temp;
	int			len;

	temp = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	array = read_1ine(fd, array);
	if (!array || array[0] == '\0')
	{
		clean(&array, temp);
		return (NULL);
	}
	len = line_length(array);
	line = ft_substr(array, 0, len + 1);
	if (line_length(array) != ft_strlen(array))
	{
		temp = array;
		array = ft_substr(array, len + 1, ft_strlen(array) - len);
		free(temp);
	}
	else
		clean(&array, temp);
	return (line);
}
char **inserttoarr(int fd)
{
	char **map;
    char *line;
    int i=0;
    int map_size=0;

    line = get_next_line(fd);
	if(!line)
	{
		printf("Error\n");
		return NULL;
	}
    map_size=strlen(line);
    map= (char **)malloc(sizeof(char *)* map_size);
    if(!map)
    {
        printf("memory allocation failed");
        close(fd);
        return (NULL);
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
            write(1,map[j],strlen(map[j]));
            j++;
    }
   write(1,"\n",1);
	return (map);
}
int checkrec(char **map)
{
	int i=0;
	int j=0;
	int hight=0;
	int width=(int)strlen(map[0]);
	//printf("%i\n",width);
	while(map[hight])
	{
		//printf("%ld\n",strlen(map[hight]));
		if((int)strlen(map[hight])!=width)
			return 0;
		hight++;
	}
	while(i<hight)
	{
		j=0;
		while(map[i][j]!='\0')
			j++;
		if(j!=width)
			return 0;
		i++;
	}
	return 1;
}

int checkborder(char **map)
{
	int i=0;
	int j=0;
	int width=(int)strlen(map[0]);
	while(map[i])
		i++;
	//printf("%i\n",i);
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
	int width=(int)strlen(map[0]);
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
// find_xy(char **map)
// {

// }
int main ()
{
	int fd;

	fd = open("text.txt",O_RDONLY);
	if (fd == -1)
    {
        printf("error reading the file\n");
        return 0;
    }
	char **map=inserttoarr(fd);
	if(map==NULL)
	{
		printf("error\n");
		return 0;
	}
	else
		printf("successfull\n");
	//checkrec(map);
	printf("%d\n",checkborder(map));
	return (0);
}
