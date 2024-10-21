#include "push_swap.h"

t_list	*generate_a(int argc, char **argv)
{
	int		*num;
	t_list	*new;
	t_list	*a;

	a = NULL;
	while (--argc)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			free_list(a);
			return (NULL);
		}
		*num = ft_atoi(argv[argc]);
		new = ft_lstnew(num);
		if (!new)
		{
			free(num);
			free_list(a);
			return (NULL);
		}
		ft_lstadd_front(&a, new);
	}
	return (a);
}

int	is_sorted(t_list *lst)
{
	int	biggest;

	biggest = INT32_MIN;
	while (lst)
	{
		if (*(int *)lst->content < biggest)
			return (0);
		biggest = *(int *)lst->content;
		lst = lst->next;
	}
	return (1);
}

void	print_list(t_list *lst)
{
	while (lst)
	{
		printf("%d ", *(int *)lst->content);
		lst = lst->next;
	}
	printf("\n");
}
