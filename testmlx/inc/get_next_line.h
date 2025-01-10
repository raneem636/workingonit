/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: raneem <raneem@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:23:03 by rabusala          #+#    #+#             */
/*   Updated: 2025/01/08 20:29:18 by raneem           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 9
# endif

# include <fcntl.h>
# include <stddef.h>
//# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char	*ft_substr(char *s, int start, int length);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *str);
int		line_length(char *str);
int		ft_strlen(char *str);
char	*clean(char **array, char *ss);
char	*read_1ine(int fd, char *array);
char	*get_next_line(int fd);

#endif