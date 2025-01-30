/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:02 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 11:14:07 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_a || !stack_a->node || !stack_a->node->next)
		return ;
	temp_node = stack_a->node;
	stack_a->node = temp_node->next;
	current_node = stack_a->node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = temp_node;
	temp_node->next = NULL;
}

void	rotate_b(t_stack *stack_b)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_b || !stack_b->node || stack_b->node->next)
		return ;
	temp_node = stack_b->node;
	stack_b->node = temp_node->next;
	current_node = stack_b->node;
	while(current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = temp_node;
	temp_node->next = NULL; 
}

void	rotate_both(t_stacks *stacks)
{
	if (!stacks)
		return ;
	rotate_a(&stacks->stack_a);
	rotate_b(&stacks->stack_b);
}