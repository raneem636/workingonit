#include "push_swap.h"
void push(t_node **a, t_node **b, char *s)
{
    t_node *tmp;
    tmp = *a;
    *a = tmp->next;
    add_first(b, tmp);
    ft_putstr_fd(s,1);
}
void swap(t_node **list, char *s)
{
    t_node *a;
    t_node *b;
    a = *list;
    b = a->next;
    a->next = b->next;
    b->next = a;
    *list = b;
    ft_putstr_fd(s,1);

}
void rotate(t_node **list,char *s)
{
    t_node *tmp;
    t_node *last;

    tmp = *list;
    last = lastnode(*list);
    *list = tmp->next;
    tmp->next = NULL;
    last->next = tmp;
	ft_putstr_fd (s,1);
}
void	revrotate(t_node **list, char *s)
{
	t_node	*tmp;
	t_node	*last;

	tmp = blastnode(*list);
	last = lastnode(*list);
	last->next = (*list);
	tmp->next = NULL;
	*list = last;
}
