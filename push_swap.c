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












int rotate_target_towards_top(int index, t_inst rotate, t_inst reverse_rotate, t_list **lst)
{
	int lstsize;

	lstsize = ft_lstsize(*lst);
	if(index > 1)
	{
		if(index <= lstsize / 2 + 1)
			call_instruction(rotate, lst, NULL);
		else
			call_instruction(reverse_rotate, lst, NULL);
		return (1);
	}
	return (0);
}

void	push_in_a(t_list **a, t_list **b)
{
	// t_list *target_position;

	// target_position = ;
	while (*b)
	{
		while (rotate_target_towards_top(get_index_in_list(find_target_position_in_a(*(int *)(*b)->content, a), a), g_instructions[5], g_instructions[8], a))
			;
		call_instruction(g_instructions[3], a, b);
	}
}

void	get_min_on_top(t_list **lst)
{
	t_list	*min;

	min = find_smallest_in_list(*lst);
	while(rotate_target_towards_top(get_index_in_list(min, lst), g_instructions[5], g_instructions[8], lst))
		;
}

void	push_best_in_b(t_list *best, t_list **a, t_list **b)
{
	int	index_a;
	int	index_b;

	index_a = get_index_in_list(best, a);
	index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	while (index_a > 1 && index_b > 1)
	{
		if (index_a <= ft_lstsize(*a) / 2 + 1 && index_b <= ft_lstsize(*b) / 2 + 1)
			call_instruction(g_instructions[7], a, b);
		else if (index_a > ft_lstsize(*a) / 2 + 1 && index_b > ft_lstsize(*b) / 2 + 1)
			call_instruction(g_instructions[10], a, b);
		else
			break ;
		index_a = get_index_in_list(best, a);
		index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	}
	index_a = get_index_in_list(best, a);
	while (index_a > 1)
	{
		if (index_a <= ft_lstsize(*a) / 2 + 1)
			call_instruction(g_instructions[5], a, b);
		else
			call_instruction(g_instructions[8], a, b);
		index_a = get_index_in_list(best, a);
	}
	index_b = get_index_in_list(find_target_position_in_b(*(int *)best->content, b), b);
	while (index_b > 1)
	{
		if (index_b <= ft_lstsize(*b) / 2 + 1)
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
	if(ft_lstsize(*a) > 3)
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
	push_in_a(a, b);
	get_min_on_top(a);
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
		call_instruction(g_instructions[0], &a, NULL);
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
