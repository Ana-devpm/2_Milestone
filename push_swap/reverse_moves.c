/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:56 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 11:43:45 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot_a(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_a || !stack_a->node || !stack_a->node->next)
		return ;
	current_node = stack_a->node;
	while (current_node->next->next != NULL)
	{
		current_node = current_node->next;
	}
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = stack_a->node;
	stack_a->node = temp_node;
}

void	reverse_rot_b(t_stack *stack_b)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_b || !stack_b->node || stack_b->node->next)
		return ;
	current_node = stack_b->node;
	while (current_node->next->next != NULL)
	{
		current_node = current_node->next;
	}
	temp_node = current_node->next;
	current_node->next = NULL;
	temp_node->next = stack_b->node;
	stack_b->node = temp_node;
}

void	reverse_rot_both(t_stacks *stacks)
{
	if (!stacks)
		return ;
	reverse_rot_a (&stacks->stack_a);
	reverse_rot_b (&stacks->stack_b);
}
