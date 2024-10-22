#include "push_swap.h"

void exit_error(t_list *a, char **sargv, char **argv, int argc)
{
	ft_putstr_fd("Error\n", 2);
	free_list(a);
	if(sargv != argv + 1)
		free_split(sargv, argc);
	exit(1);
}

void exit_success(t_list *a, char **sargv, char **argv, int argc)
{
	free_list(a);
	if(sargv != argv + 1)
		free_split(sargv, argc);
	exit(0);
}

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}