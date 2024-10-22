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

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_inst
{
	char	*instruction;
	void	(*func_a)(t_list **);
	void	(*func_b)(t_list **);
	void	(*func_ab)(t_list **, t_list **);
}	t_inst;

//utils_instructions
void	swap(t_list **lst);
void	push(t_list **dst, t_list **src);
void	rotate(t_list **lst);
void	reverse_rotate(t_list **lst);
void	call_instruction(t_inst instruction, t_list **a, t_list **b);

//utils_checks
int	is_argv_valid(int argc, char **argv, t_list *a);

//utils_lists
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_list(t_list *lst);

//utils_split
char	**ft_split(const char *str, char c);
char	**free_split(char **split, int count);

//utils_strings
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

//utils_strings_2
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

//utils_other
void	exit_error(t_list *a, char **sargv, char **argv, int argc);
void	exit_success(t_list *a, char **sargv, char **argv, int argc);
int		max(int a, int b);

//utils_algo
int		is_sorted(t_list *lst);
t_list	*find_biggest_in_list(t_list *lst);
t_list	*find_smallest_in_list(t_list *lst);
t_list	*find_target_position_in_b(int avalue, t_list **b);
t_list	*find_target_position_in_a(int bvalue, t_list **a);

//utils_algo_2
int		get_index_in_list(t_list *target, t_list **lst);
int		get_number_of_reverses(int index, int lstsize);

//debug
void	print_list(t_list *lst);

#endif