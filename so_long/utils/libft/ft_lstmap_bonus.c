/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 09:05:17 by afailde-          #+#    #+#             */
/*   Updated: 2025/04/15 13:27:33 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*node;

	new_list = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		node = ft_lstnew(lst->content);
		if (!node)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		node->content = f(node->content);
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}
