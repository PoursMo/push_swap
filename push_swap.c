/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:08 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/18 17:46:53 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const t_inst	g_instructions[11] = {
{"sa\n", swap, NULL, NULL},
{"sb\n", NULL, swap, NULL},
{"ss\n", swap, swap, NULL},
{"pa\n", NULL, NULL, push},
{"pb\n", NULL, NULL, push},
{"ra\n", rotate, NULL, NULL},
{"rb\n", NULL, rotate, NULL},
{"rr\n", rotate, rotate, NULL},
{"rra\n", reverse_rotate, NULL, NULL},
{"rrb\n", NULL, reverse_rotate, NULL},
{"rrr\n", reverse_rotate, reverse_rotate, NULL}
};

void	sort_3_nums(t_list **lst)
{
	int	values[3];

	values[0] = *(int *)(*lst)->content;
	values[1] = *(int *)(*lst)->next->content;
	values[2] = *(int *)(*lst)->next->next->content;
	if (values[0] > values[1] && values[0] > values[2])
	{
		call_instruction(g_instructions[5], lst, NULL);
		if (!is_sorted(*lst))
			call_instruction(g_instructions[0], lst, NULL);
	}
	else if (values[0] < values[1] && values[0] < values[2])
	{
		call_instruction(g_instructions[8], lst, NULL);
		call_instruction(g_instructions[0], lst, NULL);
	}
	else if (values[1] > values[2])
		call_instruction(g_instructions[8], lst, NULL);
	else
		call_instruction(g_instructions[0], lst, NULL);
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

int	get_index_in_list(t_list *target, t_list **lst)
{
	t_list	*i;
	int		index;

	if (!target)
		return (1);
	i = *lst;
	index = 1;
	while (i != target)
	{
		index++;
		i = i->next;
	}
	return (index);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	get_number_of_reverses(int index, int lstsize)
{
	if (index <= lstsize / 2)
		return (index - 1);
	return lstsize - index + 1;
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

void	push_in_a(t_list **a, t_list **b)
{
	int	index;

	while (*b)
	{
		index = get_index_in_list(find_target_position_in_a(*(int *)(*b)->content, a), a);
		while (index > 1)
		{
			if (index <= ft_lstsize(*a) / 2)
				call_instruction(g_instructions[5], a, b);
			else
				call_instruction(g_instructions[8], a, b);
			index = get_index_in_list(find_target_position_in_a(*(int *)(*b)->content, a), a);
		}
		call_instruction(g_instructions[3], a, b);
	}
}

void	get_min_on_top(t_list **lst)
{
	t_list	*min;
	int		index;

	min = find_smallest_in_list(*lst);
	index = get_index_in_list(min, lst);
	while (index > 1)
	{
		if (index <= ft_lstsize(*lst) / 2)
			call_instruction(g_instructions[5], lst, NULL);
		else
			call_instruction(g_instructions[8], lst, NULL);
		index = get_index_in_list(min, lst);
	}
}

void	push_best_in_b(t_list *best, t_list **a, t_list **b)
{
	int	index_a;
	int	index_b;

	index_a = get_index_in_list(best, a);
	index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	while (index_a > 1 && index_b > 1)
	{
		if (index_a <= ft_lstsize(*a) / 2 && index_b <= ft_lstsize(*b) / 2)
			call_instruction(g_instructions[7], a, b);
		else if (index_a > ft_lstsize(*a) / 2 && index_b > ft_lstsize(*b) / 2)
			call_instruction(g_instructions[10], a, b);
		else
			break ;
		index_a = get_index_in_list(best, a);
		index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	}
	index_a = get_index_in_list(best, a);
	while (index_a > 1)
	{
		if (index_a <= ft_lstsize(*a) / 2)
			call_instruction(g_instructions[5], a, b);
		else
			call_instruction(g_instructions[8], a, b);
		index_a = get_index_in_list(best, a);
	}
	index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	while (index_b > 1)
	{
		if (index_b <= ft_lstsize(*b) / 2)
			call_instruction(g_instructions[6], a, b);
		else
			call_instruction(g_instructions[9], a, b);
		index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	}
	call_instruction(g_instructions[4], b, a);
}

void	push_swap(t_list **a, t_list **b)
{
	t_list	*i;
	t_list	*best;
	int		asize;
	int		bsize;
	int		btarget_index;
	int		aindex;
	int		inst_count_min;
	int		inst_count;

	call_instruction(g_instructions[4], b, a);
	call_instruction(g_instructions[4], b, a);
	while (!is_sorted(*a) && ft_lstsize(*a) > 3)
	{
		i = *a;
		aindex = 1;
		inst_count_min = INT32_MAX;
		bsize = ft_lstsize(*b);
		asize = ft_lstsize(*a);
		while (i)
		{
			btarget_index = get_index_in_list(find_target_position_in_b(*(int *)i->content, b), b);
			if ((btarget_index <= bsize / 2 && aindex <= asize / 2) || (btarget_index > bsize / 2 && aindex > asize / 2))
				inst_count = max(get_number_of_reverses(btarget_index, bsize), get_number_of_reverses(aindex, asize));
			else
				inst_count = get_number_of_reverses(aindex, asize) + get_number_of_reverses(btarget_index, bsize);
			if (inst_count < inst_count_min)
			{
				best = i;
				inst_count_min = inst_count;
			}
			i = i->next;
			aindex++;
		}
		if (best)
			push_best_in_b(best, a, b);
	}
	if (!is_sorted(*a))
		sort_3_nums(a);
	push_in_a(a, b);
	get_min_on_top(a);
}



int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if(argc == 1)
		return (0);
	a = generate_a(argc, argv);
	b = NULL;
	if (!a || !is_argv_valid(argc, argv, a))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	if (is_sorted(a))
		return (0);
	if (argc == 3)
	{
		ft_putstr_fd("sa\n", 1);
		swap(&a);
		return (0);
	}
	if (argc == 4)
	{
		sort_3_nums(&a);
		return (0);
	}
	push_swap(&a, &b);
	free_list(a);
}
