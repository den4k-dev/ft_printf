#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res;
	t_list	*new_el;

	if (!lst || !f || !del)
		return (NULL);
	res = ft_lstnew(f(lst ->content));
	if (res == NULL)
	{
		ft_lstclear(&lst, del);
		return (NULL);
	}
	lst = lst ->next;
	while (lst)
	{
		new_el = ft_lstnew(f(lst ->content));
		if (!new_el)
		{
			ft_lstclear(&res, del);
			ft_lstclear(&lst, del);
			break ;
		}
		ft_lstadd_back(&res, new_el);
		lst = lst ->next;
	}
	return (res);
}
