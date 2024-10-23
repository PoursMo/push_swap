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

# include <stdio.h> //debug

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
void	call_instruction(char *instruction, t_list **a, t_list **b);

//utils_setup
int		is_argv_valid(int argc, char **argv, t_list *a);

//utils_setup_2
void	setup(t_list **a, int *argc, char **argv, char ***sargv);

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
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//utils_other
void	free_all(t_list *a, char **sargv, char **argv, int argc);
void	exit_error(t_list *a, char **sargv, char **argv, int argc);
void	exit_success(t_list *a, char **sargv, char **argv, int argc);
int		max(int a, int b);

//utils_algo
int		is_sorted(t_list *lst);
t_list	*find_biggest_in_list(t_list *lst);
t_list	*find_smallest_in_list(t_list *lst);
t_list	*find_targ_pos_in_b(int avalue, t_list **b);
t_list	*find_targ_pos_in_a(int bvalue, t_list **a);

//utils_algo_2
int		lstindex(t_list *target, t_list *lst);
int		get_rev_count(int index, int lstsize);
void	sort_3_nums(t_list **lst);
void	rotate_target_topa(t_list *target, t_list **a);
void	rotate_target_topb(t_list *target, t_list **b);

//utils_algo_3
void	push_all_b_in_a(t_list **a, t_list **b);
void	push_best_in_b(t_list *best, t_list **a, t_list **b);
void	initial_push_to_b(t_list **a, t_list **b);
int		get_ins_count(t_list **a, t_list **b, t_list *i);
t_list	*get_best(t_list **a, t_list **b);

//debug
void	print_list(t_list *lst);

#endif