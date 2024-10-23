#include "push_swap.h"

static t_list	*generate_a(int argc, char **argv)
{
	int		*num;
	t_list	*new;
	t_list	*a;

	a = NULL;
	while (--argc >= 0)
	{
		num = malloc(sizeof(int));
		if (!num)
		{
			free_list(a);
			return (NULL);
		}
		*num = ft_atoi(argv[argc]);
		new = ft_lstnew(num);
		if (!new)
		{
			free(num);
			free_list(a);
			return (NULL);
		}
		ft_lstadd_front(&a, new);
	}
	return (a);
}

static void	perform_checks(t_list *a, int argc, char **sargv, char **argv)
{
	if (!a || !is_argv_valid(argc, sargv, a))
		exit_error(a, sargv, argv, argc);
	if (is_sorted(a))
		exit_success(a, sargv, argv, argc);
	if (ft_lstsize(a) == 2)
	{
		call_instruction("sa\n", &a, NULL);
		exit_success(a, sargv, argv, argc);
	}
	if (ft_lstsize(a) == 3)
	{
		sort_3_nums(&a);
		exit_success(a, sargv, argv, argc);
	}
}

void	setup(t_list **a, int *argc, char **argv, char ***sargv)
{
	*sargv = argv + 1;
	if (*argc == 2)
	{
		*sargv = ft_split(argv[1], ' ');
		*argc = 0;
		while ((*sargv)[*argc])
			(*argc)++;
	}
	else
		(*argc)--;
	*a = generate_a(*argc, *sargv);
	perform_checks(*a, *argc, *sargv, argv);
}
