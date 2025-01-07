/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilss.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:13:36 by rabusala          #+#    #+#             */
/*   Updated: 2024/12/30 13:14:42 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"
int	find_max(t_node **list)
{
	t_node	*tmp;
	int		max;
	int		max_bits;

	tmp = (*list);
	max = tmp->info;
	max_bits = 0;
	while (tmp != NULL)
	{
		if (tmp->info > max)
			max = tmp->info;
		tmp = tmp->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

int	find_min(t_node **list)
{
	t_node	*tmp;
	int		min;

	tmp = (*list);
	min = 2147483647;
	while (tmp != NULL)
	{
		if ((tmp->info) < min && (tmp->status != 1))
			min = tmp->info;
		tmp = tmp->next;
	}
	return (min);
}
int	find_minn(t_node **list)
{
	t_node	*tmp;
	int		min;

	tmp = (*list);
	min = 2147483647;
	while (tmp != NULL)
	{
		if ((tmp->info) < min)
			min = tmp->info;
		tmp = tmp->next;
	}
	return (min);
}
void	switchh(t_node **list)
{
	t_node	*tmp;
	int		i;
	int		min;

	i = 0;
	while (1)
	{
		min = find_min(list);
		if (min == 2147483647)
			break ;
		tmp = *list;
		while (tmp != NULL)
		{
			if (tmp->info == min && tmp->status != 1)
			{
				tmp->info = i;
				tmp->status = 1;
				i++;
				break ;
			}
			tmp = tmp->next;
		}
	}
}

int	l_size(t_node **a)
{
	t_node	*tmp;
	int		count;

	tmp = *a;
	count = 0;
	while (tmp != 0)
	{
		count++;
		tmp = tmp->next;
	}
	return (count);
}
