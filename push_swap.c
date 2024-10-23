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

void	push_swap(t_list **a, t_list **b)
{
	initial_push_to_b(a, b);
	while (!is_sorted(*a) && ft_lstsize(*a) > 3)
		push_best_in_b(get_best(a, b), a, b);
	if (!is_sorted(*a))
		sort_3_nums(a);
	push_all_b_in_a(a, b);
	rotate_target_topa(find_smallest_in_list(*a), a);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**sargv;

	if (argc == 1)
		return (0);
	setup(&a, &argc, argv, &sargv);
	b = NULL;
	push_swap(&a, &b);
	free_all(a, sargv, argv, argc);
	return (0);
}
