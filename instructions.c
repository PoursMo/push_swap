/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:34 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/16 16:23:58 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap(t_list **lst)
{
	if(!lst || !*lst || !(*lst)->next)
		return ;
	t_list *temp;

	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
}

void push(t_list **dst, t_list **src)
{
	t_list *temp;
	
	if(!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

void	reverse(t_list **lst)
{
	t_list *i;
	t_list *temp;

	if(!lst || !*lst || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	i = *lst;
	while(i->next)
		i = i->next;
	i->next = temp;
	temp->next = NULL;
}

void	reverse_rotate(t_list **lst)
{
	t_list *i;
	t_list *last;
	
	if(!lst || !*lst || !(*lst)->next)
		return ;
	i = *lst;
	while(i->next->next)
		i = i->next;
	last = i->next;
	i->next = NULL;
	last->next = *lst;
	*lst = last;
}