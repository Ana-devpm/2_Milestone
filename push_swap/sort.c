/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:32:24 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 16:54:52 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	is_sorted(t_stack *stack_a)
{
	t_node	*current_node;

	if (!stack_a || stack_a->size < 1)
		return (TRUE);
	current_node = stack_a->node;
	while (current_node->next)
	{
		if (current_node->index > current_node->next->index)
			return (FALSE);
		current_node = current_node->next;
	}
	return (TRUE);
}

void	sorter()
{

}