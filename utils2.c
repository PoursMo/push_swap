/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:06 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/16 16:54:46 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}

void free_list(t_list *lst)
{
	t_list *temp;

	while(lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

t_list *generate_a(int argc, char **argv)
{
	int *num;
	t_list *new;
	t_list *a;

	a = NULL;
	while(--argc)
	{
		num = malloc(sizeof(int));
		if(!num)
		{
			free_list(a);
			return (NULL);
		}
		*num = ft_atoi(argv[argc]);
		new = ft_lstnew(num);
		if(!new)
		{
			free(num);
			free_list(a);
			return (NULL);
		}
		ft_lstadd_front(&a, new);
	}
	return (a);
}

int is_ordered(t_list *lst)
{
	int biggest;

	biggest = INT32_MIN;
	while(lst)
	{
		if(*(int*)lst->content < biggest)
			return (0);
		biggest = *(int*)lst->content;
		lst = lst->next;
	}
	return (1);
}
