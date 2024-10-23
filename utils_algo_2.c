#include "push_swap.h"

int	lstindex(t_list *target, t_list *lst)
{
	t_list	*i;
	int		index;

	if (!target)
		return (1);
	i = lst;
	index = 1;
	while (i != target)
	{
		index++;
		i = i->next;
	}
	return (index);
}

int	get_rev_count(int index, int lstsize)
{
	if (index <= lstsize / 2 + 1)
		return (index - 1);
	return (lstsize - index + 1);
}

void	sort_3_nums(t_list **lst)
{
	int	values[3];

	values[0] = *(int *)(*lst)->content;
	values[1] = *(int *)(*lst)->next->content;
	values[2] = *(int *)(*lst)->next->next->content;
	if (values[0] > values[1] && values[0] > values[2])
	{
		call_instruction("ra\n", lst, NULL);
		if (!is_sorted(*lst))
			call_instruction("sa\n", lst, NULL);
	}
	else if (values[0] < values[1] && values[0] < values[2])
	{
		call_instruction("rra\n", lst, NULL);
		call_instruction("sa\n", lst, NULL);
	}
	else if (values[1] > values[2])
		call_instruction("rra\n", lst, NULL);
	else
		call_instruction("sa\n", lst, NULL);
}

void	rotate_target_topa(t_list *target, t_list **a)
{
	int	lstsize;
	int	index;

	lstsize = ft_lstsize(*a);
	index = lstindex(target, *a);
	while (index > 1)
	{
		if (index <= lstsize / 2 + 1)
			call_instruction("ra\n", a, NULL);
		else
			call_instruction("rra\n", a, NULL);
		index = lstindex(target, *a);
	}
}

void	rotate_target_topb(t_list *target, t_list **b)
{
	int	lstsize;
	int	index;

	lstsize = ft_lstsize(*b);
	index = lstindex(target, *b);
	while (index > 1)
	{
		if (index <= lstsize / 2 + 1)
			call_instruction("rb\n", NULL, b);
		else
			call_instruction("rrb\n", NULL, b);
		index = lstindex(target, *b);
	}
}
