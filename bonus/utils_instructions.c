/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 15:31:34 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/18 17:21:22 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	s(t_list **lst)
{
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = temp;
}

static void	p(t_list **dst, t_list **src)
{
	t_list	*temp;

	if (!src || !*src)
		return ;
	temp = *src;
	*src = (*src)->next;
	temp->next = *dst;
	*dst = temp;
}

static void	r(t_list **lst)
{
	t_list	*i;
	t_list	*temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = *lst;
	*lst = (*lst)->next;
	i = *lst;
	while (i->next)
		i = i->next;
	i->next = temp;
	temp->next = NULL;
}

static void	rr(t_list **lst)
{
	t_list	*i;
	t_list	*last;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	i = *lst;
	while (i->next->next)
		i = i->next;
	last = i->next;
	i->next = NULL;
	last->next = *lst;
	*lst = last;
}

void	call_instruction(char *instruction, t_list **a, t_list **b)
{
	static const t_inst	instructions[11] = {
	{"sa\n", s, NULL, NULL}, {"sb\n", NULL, s, NULL}, {"ss\n", s, s, NULL},
	{"pa\n", NULL, NULL, p}, {"pb\n", NULL, NULL, p},
	{"ra\n", r, NULL, NULL}, {"rb\n", NULL, r, NULL}, {"rr\n", r, r, NULL},
	{"rra\n", rr, NULL, NULL}, {"rrb\n", NULL, rr, NULL},
	{"rrr\n", rr, rr, NULL}};
	int					i;

	i = 0;
	while (i < 11)
	{
		if (ft_strncmp(instruction, instructions[i].instruction, 4) == 0)
		{
			if (instructions[i].func_a)
				instructions[i].func_a(a);
			if (instructions[i].func_b)
				instructions[i].func_b(b);
			if (instructions[i].func_ab)
				instructions[i].func_ab(a, b);
			return ;
		}
		i++;
	}
}
