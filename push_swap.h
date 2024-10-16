/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:10 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/16 17:11:52 by aloubry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;


void	swap(t_list **lst);
t_list	*push(t_list **dst, t_list **src);
void	reverse_rotate(t_list **lst);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	free_list(t_list *lst);
t_list	*generate_a(int argc, char **argv);
int		is_ordered(t_list *lst);

void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
void	print_list(t_list *lst);

#endif