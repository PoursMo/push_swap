#include "checker.h"

void checker(t_list **a, t_list **b)
{
	char	*line;

	line = get_next_line(1);
	while(line)
	{
		call_instruction(line, a, b);
		free(line);
		line = get_next_line(1);
	}
	if(is_sorted(*a) && !*b)
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
