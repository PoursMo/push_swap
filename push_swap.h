/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubry <aloubry@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 16:47:10 by aloubry           #+#    #+#             */
/*   Updated: 2024/10/18 17:02:12 by aloubry          ###   ########.fr       */
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

typedef struct s_inst
{
	char *instruction;
	void (*func_a)(t_list **);
	void (*func_b)(t_list **);
	void (*func_ab)(t_list **, t_list **);
}	t_inst;

//utils_instructions
void	swap(t_list **lst);
void	push(t_list **dst, t_list **src);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	call_instruction(t_inst instruction, t_list **a, t_list **b);

//utils_lists
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_list(t_list *lst);

//utils2
t_list	*generate_a(int argc, char **argv);
int		is_sorted(t_list *lst);
void	print_list(t_list *lst);

//utils
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *nptr);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif