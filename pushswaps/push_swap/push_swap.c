/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:13:36 by rabusala          #+#    #+#             */
/*   Updated: 2024/12/30 16:09:54 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(int c, char **v)
{
	int	i;

	i = 1;
	t_node *a = NULL;
	t_node *b=NULL;
	i=1;
	if (c <= 2)
	{
		write(2,"Error\n",6);
		return 0;

	}
	printf("%d",checknum(c,v));
// 	while (i < c)
// 	{
// 		add_node(&a, v[i]);
// 		i++;
// 	}

// 	 print_list(a);
// 	switchh(&a);
// 	print_list(a);
// 	if(c==3)
// 		sort_2(&a);
// 	else if(c==4)
// 		sort_3(&a);
// 	else if(c==5)
// 		sort_4(&a, &b);
// 	else if (c == 6)
// 	sort_5(&a, &b);
// 	else
// 	{
// 		int d=l_size(&a);
// 		int ab=find_max(&a);
// 		multisort(&a,&b,ab,d);
// 	}
}


