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

void	push_all_b_in_a(t_list **a, t_list **b)
{
	while (*b)
	{
		rotate_target_topa(find_target_position_in_a(*(int *)(*b)->content, a), a);
		call_instruction("pa\n", a, b);
	}
}

void	push_best_in_b(t_list *best, t_list **a, t_list **b)
{
	int	index_a;
	int	index_b;
	int size_a;
	int size_b;
	t_list *target;

	target = find_target_position_in_b(*(int *)best->content, b);
	index_a = lstindex(best, *a);
	index_b = lstindex(target, *b);
	size_a = ft_lstsize(*a);
	size_b = ft_lstsize(*b);
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
	rotate_target_topb(find_target_position_in_b(*(int *)best->content, b), b);
	call_instruction("pb\n", b, a);
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

	call_instruction("pb\n", b, a);
	if(ft_lstsize(*a) > 3)
		call_instruction("pb\n", b, a);
	while (!is_sorted(*a) && ft_lstsize(*a) > 3)
	{
		i = *a;
		aindex = 1;
		inst_count_min = INT32_MAX;
		bsize = ft_lstsize(*b);
		asize = ft_lstsize(*a);
		while (i)
		{
			btarget_index = lstindex(find_target_position_in_b(*(int *)i->content, b), *b);
			if ((btarget_index <= bsize / 2 + 1 && aindex <= asize / 2 + 1) || (btarget_index > bsize / 2 + 1 && aindex > asize / 2 + 1))
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
	push_all_b_in_a(a, b);
	rotate_target_topa(find_smallest_in_list(*a), a);
}

t_list	*generate_list(int argc, char **argv)
{
	int		*num;
	t_list	*new;
	t_list	*a;

	a = NULL;
	while (--argc >= 0)
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

t_list *setup(int argc, char **argv)
{
	t_list	*a;
	char **sargv;

	sargv = argv + 1;
	if(argc == 2)
	{
		sargv = ft_split(argv[1], ' ');
		argc = 0;
		while (sargv[argc])
			argc++;
	}
	else
		argc--;
	a = generate_list(argc, sargv);
	if (!a || !is_argv_valid(argc, sargv, a))
		exit_error(a, sargv, argv, argc);
	if (is_sorted(a))
		exit_success(a, sargv, argv, argc);
	if (ft_lstsize(a) == 2)
	{
		call_instruction("sa\n", &a, NULL);
		exit_success(a, sargv, argv, argc);
	}
	if (ft_lstsize(a) == 3)
	{
		sort_3_nums(&a);
		exit_success(a, sargv, argv, argc);
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	if(argc == 1)
		return (0);
	a = setup(argc, argv);
	b = NULL;
	push_swap(&a, &b);
	free_list(a);
}
