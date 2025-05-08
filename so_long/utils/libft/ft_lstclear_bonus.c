/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:17:19 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 15:58:07 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*curr_node;
	t_list	*aux_node;

	curr_node = *lst;
	while (curr_node)
	{
		aux_node = curr_node->next;
		ft_lstdelone(curr_node, del);
		curr_node = aux_node;
	}
	*lst = NULL;
}
