#include "push_swap.h"

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

t_list	*find_biggest_in_list(t_list *lst)
{
	t_list	*biggest;

	biggest = lst;
	while (lst)
	{
		if (*(int *)lst->content > *(int *)biggest->content)
			biggest = lst;
		lst = lst->next;
	}
	return (biggest);
}

t_list	*find_smallest_in_list(t_list *lst)
{
	t_list	*smallest;

	smallest = lst;
	while (lst)
	{
		if (*(int *)lst->content < *(int *)smallest->content)
			smallest = lst;
		lst = lst->next;
	}
	return (smallest);
}

t_list	*find_target_position_in_b(int avalue, t_list **b)
{
	t_list	*i;

	i = *b;
	while (i->next)
	{
		if (avalue < *(int *)i->content && avalue > *(int *)i->next->content)
			return (i->next);
		i = i->next;
	}
	if (avalue < *(int *)i->content && avalue > *(int *)(*b)->content)
		return (NULL);
	return (find_biggest_in_list(*b));
}

t_list	*find_target_position_in_a(int bvalue, t_list **a)
{
	t_list	*i;

	i = *a;
	while (i->next)
	{
		if (bvalue > *(int *)i->content && bvalue < *(int *)i->next->content)
			return (i->next);
		i = i->next;
	}
	if (bvalue > *(int *)i->content && bvalue < *(int *)(*a)->content)
		return (NULL);
	return (find_smallest_in_list(*a));
}
