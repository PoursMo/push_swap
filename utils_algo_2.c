#include "push_swap.h"

int	get_index_in_list(t_list *target, t_list **lst)
{
	t_list	*i;
	int		index;

	if (!target)
		return (1);
	i = *lst;
	index = 1;
	while (i != target)
	{
		index++;
		i = i->next;
	}
	return (index);
}

int	get_number_of_reverses(int index, int lstsize)
{
	if (index <= lstsize / 2 + 1)
		return (index - 1);
	return (lstsize - index + 1);
}