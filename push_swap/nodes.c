/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:06:23 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 18:14:47 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @warning MALLOC
 */
t_node	*lst_malloc_node(int nbr)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->index;
	new_node->nbr;
	new_node->next = NULL;
	return (new_node);
}

/**
 * @warning MALLOC
 */
t_bool	malloc_number_for_stack(t_stack	*stack, int nbr)
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = lst_malloc_node(nbr);
	if (!new_node)
	{
		printf("Error: No se pudo crear el nodo\n");
		return (FALSE);
	}
	if (stack->node == NULL)
		stack->node = new_node;
	else
	{
		current_node = stack->node;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	stack->size++;
	return (TRUE);
}
