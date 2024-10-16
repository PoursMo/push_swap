/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:08 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/16 17:04:01 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// void	algo(t_list **a, t_list **b)
// {
// 	int count;
// 	t_list *first_elem;

// 	count = 0;
// 	while((*a)->next)
// 	{
// 		count++;
// 		if(count == 1)
// 			first_elem = *a;
// 		if(count == 2 && *(int*)((*a)->content) < *(int*)(first_elem->content))
// 		{
// 			ft_putstr_fd("sa\n", 1);
// 			swap(first_elem);
// 			algo(&first_elem, b);
// 			return ;
// 		}
// 		*a = (*a)->next;
// 	}
// 	if(*(int*)((*a)->content) < *(int*)(first_elem->content))
// 	{
// 		ft_putstr_fd("rra\n", 1);
// 		reverse_rotate(&first_elem);
// 		algo(&first_elem, b);
// 		return ;
// 	}
// 	else if (!is_ordered(first_elem))
// 	{
// 		ft_putstr_fd("pb\n", 1);
// 		push(b, &first_elem);
// 		algo(&first_elem, b);
// 		return ;
// 	}
// 	else
// 	{
// 		if(*b)
// 		{
// 			ft_putstr_fd("pa\n", 1);
// 			first_elem = push(&first_elem, b);
// 		}
// 		if(*b)
// 			algo(&first_elem, b);
// 		if(!is_ordered(first_elem) && !*b)
// 			algo(&first_elem, b);
// 		return ;
// 	}

// }


void push_swap(t_list **a, t_list **b)
{

}

int is_list_valid(t_list *a)
{
	t_list *i;

	while(a)
	{
		if(*(int*)a->content > INT32_MAX || *(int*)a->content < INT32_MIN)
			return (0);
		i = a->next;
		while(i)
		{
			if(*(int*)i->content == *(int*)a->content)
				return (0);
			i = i->next;
		}
		a = a->next;
	}
	return (1);
}

int main(int argc, char **argv)
{
	t_list *a;
	t_list *b;

	a = generate_a(argc, argv);
	if(argc < 3 || !a || !is_list_valid(a))
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	push_swap(&a, &b);
	free_list(a);
}
