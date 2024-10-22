#include "push_swap.h"

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}