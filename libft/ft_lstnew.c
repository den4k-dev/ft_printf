#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*el;

	el = malloc(sizeof(t_list));
	if (el)
	{
		el -> content = content;
		el ->next = NULL;
	}
	return (el);
}
