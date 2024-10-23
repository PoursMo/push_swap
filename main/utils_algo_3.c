#include "push_swap.h"

void	push_all_b_in_a(t_list **a, t_list **b)
{
	while (*b)
	{
		rotate_target_topa(find_targ_pos_in_a(*(int *)(*b)->content, a), a);
		call_instruction("pa\n", a, b);
	}
}

void	push_best_in_b(t_list *best, t_list **a, t_list **b)
{
	int		index_a;
	int		index_b;
	int		size_a;
	int		size_b;
	t_list	*target;

	target = find_targ_pos_in_b(*(int *)best->content, b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
	index_a = lstindex(best, *a);
	index_b = lstindex(target, *b);
	while (index_a > 1 && index_b > 1)
	{
		if (index_a <= size_a / 2 + 1 && index_b <= size_b / 2 + 1)
			call_instruction("rr\n", a, b);
		else if (index_a > size_a / 2 + 1 && index_b > size_b / 2 + 1)
			call_instruction("rrr\n", a, b);
		else
			break ;
		index_a = lstindex(best, *a);
		index_b = lstindex(target, *b);
	}
	rotate_target_topa(best, a);
	rotate_target_topb(find_targ_pos_in_b(*(int *)best->content, b), b);
	call_instruction("pb\n", b, a);
}

void	initial_push_to_b(t_list **a, t_list **b)
{
	call_instruction("pb\n", b, a);
	if (ft_lstsize(*a) > 3)
		call_instruction("pb\n", b, a);
}

int	get_ins_count(t_list **a, t_list **b, t_list *i)
{
	int	a_i;
	int	btarg_i;
	int	asize;
	int	bsize;

	asize = ft_lstsize(*a);
	bsize = ft_lstsize(*b);
	a_i = lstindex(i, *a);
	btarg_i = lstindex(find_targ_pos_in_b(*(int *)i->content, b), *b);
	if ((btarg_i <= bsize / 2 + 1 && a_i <= asize / 2 + 1)
		|| (btarg_i > bsize / 2 + 1 && a_i > asize / 2 + 1))
		return (max(get_rev_count(btarg_i, bsize), get_rev_count(a_i, asize)));
	else
		return (get_rev_count(a_i, asize) + get_rev_count(btarg_i, bsize));
}

t_list	*get_best(t_list **a, t_list **b)
{
	t_list	*best;
	t_list	*i;
	int		ins_count;
	int		ins_count_min;

	i = *a;
	ins_count_min = INT32_MAX;
	while (i)
	{
		ins_count = get_ins_count(a, b, i);
		if (ins_count < ins_count_min)
		{
			best = i;
			ins_count_min = ins_count;
		}
		i = i->next;
	}
	return (best);
}
