/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hdavid <hdavid@learner.42.tech>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:37:13 by hdavid            #+#    #+#             */
/*   Updated: 2025/11/10 16:01:18 by hdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map_lst;
	t_list	*new_content;

	map_lst = NULL;
	while (lst)
	{
		new_content = ft_lstnew (f(lst->content));
		ft_lstadd_back (&map_lst, new_content);
		lst = lst->next;
	}
	if (new_content == NULL)
		del(new_content);
	return (map_lst);
}
