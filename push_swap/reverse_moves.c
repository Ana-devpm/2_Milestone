/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_moves.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:32:56 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/18 19:36:38 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rot_a(t_stack *stack_a, t_bool print)
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
	if (print == TRUE)
		write(1, "rra\n", 4);
}

void	reverse_rot_b(t_stack *stack_b, t_bool print)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_b || !stack_b->node || !stack_b->node->next)
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
	if (print == TRUE)
		write(1, "rrb\n", 4);
}

void	reverse_rot_both(t_stacks *stacks, t_bool print)
{
	if (!stacks)
		return ;
	reverse_rot_a (&stacks->stack_a, FALSE);
	reverse_rot_b (&stacks->stack_b, FALSE);
	if (print == TRUE)
		write(1, "rrr\n", 4);
}
