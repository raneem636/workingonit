/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:13:36 by rabusala          #+#    #+#             */
/*   Updated: 2024/12/30 16:12:51 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int checknum(int c, char **v)
{
    int i;
    int j;

    i = 0;
    while(i < c)
    {
        j = 0;
        while(v[i][j])
        {
            if(isdigit(v[i][j]) == 0)
                return (0);
                j++;
        }
		i++;
    }
    return (1);

}
int checkrepeat(int c, char **v)
{
	int	i;
	int	j;

	i = 0;
	while(i < c)
	{
		j = i + 1;
		while(j < c)
		{
			if (v[i][])
		}
	}
}
