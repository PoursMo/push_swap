#include "checker.h"

int	is_sorted(t_list *lst)
{
	int	biggest;

	biggest = INT32_MIN;
	while (lst)
	{
		if (*(int *)lst->content < biggest)
			return (0);
		biggest = *(int *)lst->content;
		lst = lst->next;
	}
	return (1);
}
