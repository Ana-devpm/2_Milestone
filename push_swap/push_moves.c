/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:47 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 12:36:43 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stack	*stack_a, t_stack *stack_b)
{
	t_node	*temp_node;

	if (!stack_b || !stack_b->node)
		return ;
	temp_node = stack_b->node;
	stack_b->node = temp_node->next;
	temp_node->next = stack_a->node;
	stack_a->node = temp_node;
	stack_a->size++;
	stack_b->size--;
}

void	push_b(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp_node;

	if (!stack_a || !stack_a->node)
		return ;
	temp_node = stack_a->node;
	stack_a->node = temp_node->next;
	temp_node->next = stack_b->node;
	stack_b->node = temp_node;
	stack_a->size--;
	stack_b->size++;
}
