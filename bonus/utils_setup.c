#include "checker.h"

static int	has_non_digit(char *str)
{
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		str++;
	}
	return (0);
}

static int	has_non_int32(char *str)
{
	int	strlen;
	int	is_negative;

	is_negative = str[0] == '-';
	if (is_negative)
		str++;
	strlen = ft_strlen(str);
	if (strlen > 10)
		return (1);
	if (strlen == 10)
	{
		if (is_negative && ft_strncmp(str, "2147483648", 10) > 0)
			return (1);
		if (!is_negative && ft_strncmp(str, "2147483647", 10) > 0)
			return (1);
	}
	return (0);
}

static int	has_duplicates(t_list *lst)
{
	t_list	*i;

	while (lst)
	{
		i = lst->next;
		while (i)
		{
			if (*(int *)i->content == *(int *)lst->content)
				return (1);
			i = i->next;
		}
		lst = lst->next;
	}
	return (0);
}

int	is_argv_valid(int argc, char **argv, t_list *a)
{
	while (--argc >= 0)
	{
		if (has_non_digit(argv[argc]) || has_non_int32(argv[argc]))
			return (0);
	}
	if (has_duplicates(a))
		return (0);
	return (1);
}
