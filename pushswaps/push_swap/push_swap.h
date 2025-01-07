/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rabusala <rabusala@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 15:17:11 by rabusala          #+#    #+#             */
/*   Updated: 2024/12/30 16:08:17 by rabusala         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdio.h>
#include <ctype.h>
//#include <libft.h>

typedef struct s_node
{
	int	info;
	int	status;
	struct s_node	*next;
}	t_node;

t_node	*lastnode(t_node *list);
t_node	*blastnode(t_node *list);
int		add_node(t_node **old, char *inf);
int		add_node(t_node **list, char *inf);
int		find_max(t_node **list);
int		find_bits(int n);
int		is_sorted(t_node **list, int size);
int		l_size(t_node **a);
int		find_msb(t_node *a);
int	find_min(t_node **list);
void rotate(t_node **list,char *s);
void	push(t_node **a, t_node **b, char *s);
void	revrotate(t_node **list, char *s);
void	swap(t_node **list, char *c);
void	add_first(t_node **list, t_node *tmp);
void	add_back(t_node **list, t_node *tmp);
void	print_list(t_node *head);
void	sort_3(t_node **list);
void	sort_2(t_node **list);
void	switchh(t_node **list);
void	multisort(t_node **a, t_node **b, int bits, int size);
void	ft_putstr_fd(char *s, int fd);
void	push_min(t_node **a, t_node **b);
void	sort_5(t_node **a, t_node **b);
void	sort_4(t_node **a, t_node **b);
int	find_minn(t_node **list);
int checknum(int c, char **v);

#endif
