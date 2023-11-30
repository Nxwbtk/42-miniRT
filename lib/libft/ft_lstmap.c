/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsirikam <bsirikam@student.42bangkok.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 09:09:23 by bsirikam          #+#    #+#             */
/*   Updated: 2022/08/10 15:01:50 by bsirikam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*n_lst;
	t_list	*dest;

	dest = NULL;
	if (!lst)
		return (NULL);
	while (lst)
	{
		n_lst = ft_lstnew(f(lst->content));
		if (!n_lst)
		{
			ft_lstclear(&lst, del);
			return (NULL);
		}
		ft_lstadd_back(&dest, n_lst);
		lst = lst->next;
	}
	return (dest);
}
