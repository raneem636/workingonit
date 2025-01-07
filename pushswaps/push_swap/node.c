#include "push_swap.h"

t_node *lastnode(t_node *list)
{
    if (!list)
        return NULL;
    while(list->next!=NULL)
        list=list->next;
    return(list);
}
t_node *blastnode(t_node *list)
{
    if (!list)
        return NULL;
    while(list->next->next!=NULL)
        list=list->next;
    return(list);
}
void add_first(t_node **list,t_node *tmp)
{
    tmp->next=NULL;
    if(!(*list))
    {
        *list=tmp;
    }
    else
    {
        tmp->next=(*list);
        (*list)=tmp;
    }
}
void	add_back(t_node **list, t_node *tmp)
{
	t_node	*last;

	if (tmp == NULL)
		return ;
	if (*list == NULL)
		*list = tmp;
	else
	{
		last=lastnode(*list);
        last->next=tmp;
	}
}
int add_node(t_node **list,char *inf)
{
    int x=atoi(inf);
    t_node *tmp;
    tmp=malloc(sizeof (t_node));
	if(!tmp)
		
    tmp->info=x;
    tmp->next=NULL;
    add_back(list,tmp);
    return 1;

}
void print_list(t_node *head)
{
    if (!head) { // Check if the list is empty
        printf("The list is empty.\n");
        return;
    }
    while (head) { // Traverse the list and print each node's value
        printf("%d -> ", head->info);
        head = head->next;
    }
    printf("NULL\n"); // Indicate the end of the list
}
void	ft_putstr_fd(char *s, int fd)

{
	while (*s)
		write (fd, &(*s++), 1);
}
