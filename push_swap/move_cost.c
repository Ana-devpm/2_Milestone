/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:55:01 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/03 16:59:42 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	mov_cost_ra(t_stack	*stack, size_t index)
{
	t_node	*current;
	size_t	result;

	result = 0;
	current = stack->node;
	while (current)
	{
		if (current->index == index)
			return (result);
		result++;
		current = current->next;
	}
	return (result);
}

size_t	get_min(t_stack *stack)
{
	t_node	*current;
	size_t	result;

	current = stack->node;
	result = current->index;
	while (current)
	{
		if (current->index < result)
			result = current->index;
		current = current->next;
	}
	return (result);
}