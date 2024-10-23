#include "checker.h"

int	is_line_ok(char *line)
{
	return (ft_strncmp(line, "sa\n", 3) == 0
		|| ft_strncmp(line, "sb\n", 3) == 0
		|| ft_strncmp(line, "ss\n", 3) == 0
		|| ft_strncmp(line, "pa\n", 3) == 0
		|| ft_strncmp(line, "pb\n", 3) == 0
		|| ft_strncmp(line, "ra\n", 3) == 0
		|| ft_strncmp(line, "rb\n", 3) == 0
		|| ft_strncmp(line, "rr\n", 3) == 0
		|| ft_strncmp(line, "rra\n", 4) == 0
		|| ft_strncmp(line, "rrb\n", 4) == 0
		|| ft_strncmp(line, "rrr\n", 4) == 0);
}

void	checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!is_line_ok(line))
		{
			free(line);
			ft_putstr_fd("Error\n", 2);
			return ;
		}
		if (ft_strncmp(line, "pb\n", 3) == 0)
			call_instruction(line, b, a);
		else
			call_instruction(line, a, b);
		free(line);
		line = get_next_line(0);
	}
	if (is_sorted(*a) && !*b)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**sargv;

	if (argc == 1)
		return (0);
	setup(&a, &argc, argv, &sargv);
	b = NULL;
	checker(&a, &b);
	free_all(a, sargv, argv, argc);
	return (0);
}
