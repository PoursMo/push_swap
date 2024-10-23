#ifndef CHECKER_H
# define CHECKER_H

# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

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

//utils_strings
void	ft_putstr_fd(char *s, int fd);
int		ft_isdigit(int c);
int		ft_atoi(const char *nptr);
size_t	ft_strlen(const char *s);

//utils_strings_2
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

//utils_lists
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
void	free_list(t_list *lst);

//get_next_line
# define MAX_FD 1024
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

typedef struct s_buffer
{
	char	buffer[BUFFER_SIZE];
	size_t	offset;
}	t_buffer;

void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

//utils_algo
int		is_sorted(t_list *lst);

//utils_split
char	**ft_split(const char *str, char c);
char	**free_split(char **split, int count);

//utils_other
void	free_all(t_list *a, char **sargv, char **argv, int argc);
void	exit_error(t_list *a, char **sargv, char **argv, int argc);
void	exit_success(t_list *a, char **sargv, char **argv, int argc);

//utils_setup
int		is_argv_valid(int argc, char **argv, t_list *a);

//utils_setup_2
void	setup(t_list **a, int *argc, char **argv, char ***sargv);

//utils_instructions
void	call_instruction(char *instruction, t_list **a, t_list **b);

#endif