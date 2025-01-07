/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortingg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:13:36 by rabusala          #+#    #+#             */
/*   Updated: 2024/12/30 15:36:58 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node **list, int size)
{
	t_node	*tmp;
	int		i;

	tmp = *list;
	i = 0;
	while (i < size)
	{
		if (tmp->info != i)
			return (0);
		i++;
		tmp = tmp->next;
	}
	return (1);
}

void	sort_2(t_node **list)
{
	t_node	*a;
	t_node	*b;

	a = (*list);
	b = a->next;
	if (a->info > b->info)
		swap(list, "sa\n");
}

void	sort_3(t_node **list)
{
	t_node	*a;
	t_node	*b;
	t_node	*c;

	a = (*list);
	b = a->next;
	c = b->next;
	if (a->info < b->info && b->info > c->info && c->info < a->info)
		revrotate(list, "rra\n");
	else if (a->info < b->info && b->info > c->info && c->info > a->info)
	{
		revrotate(list, "rra\n");
		swap(list, "sa\n");
	}
	else if (a->info > c->info && b->info < c->info)
		rotate(list, "ra\n");
	else if (a->info > b->info && b->info < c->info && c->info > a->info)
		swap(list, "sa\n");
	else if (a->info > b->info && b->info > c->info)
	{
		swap(list, "sa\n");
		revrotate(list, "rra\n");
	}
}
void	sort_4(t_node **a, t_node **b)
{
	push_min(a, b);
	sort_3(a);
	push(b, a, "pa\n");
}
void	sort_5(t_node **a, t_node **b)
{
	push_min(a, b);
	sort_4(a,b);
	push(b, a, "pa\n");
}
void	push_min(t_node **a, t_node **b)
{
	t_node	*a1;
	t_node	*b1;

	a1 = *a;
	b1 = a1->next;
	if (a1->info == find_minn(a))
	{
		push(a, b,"pb\n");
		return;
	}
	else if (b1->info == find_minn(a))
		swap(a,"sa\n");
	else if (b1->next->info == find_minn(a))
	{
		rotate(a,"ra\n");
		swap(a,"sa\n");
	}
	else if (b1->next->next->info==find_minn(a))
	{
		revrotate(a, "rra\n");
		revrotate(a, "rra\n");
	}
	else
		revrotate(a, "rra\n");
	push(a, b,"pb\n");
}
void	multisort(t_node **a, t_node **b, int bits, int size)
{
	int	i;
	int	j;
	t_node *heada;

	i = 0;
	// if (is_sorted(a, size))
	// 	return ;
	while (i < bits)
	{
		j = 0;
		while (j < size)
		{
			heada = (*a);
			if (((heada->info >> i) & 1) == 1)
				rotate(a, "ra\n");
			else
				push(a, b, "pb\n");
			j++;
		}
		while (l_size(b) != 0)
			push(b, a, "pa\n");
		if (is_sorted(a, size))
			break ;
		i++;
	}
}

