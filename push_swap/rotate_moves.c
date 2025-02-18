/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 19:33:02 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/18 20:34:22 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stack *stack_a, t_bool print)
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
	if (print == TRUE)
		write(1, "ra\n", 3);
}

void	rotate_b(t_stack *stack_b, t_bool print)
{
	t_node	*current_node;
	t_node	*temp_node;

	if (!stack_b || !stack_b->node || !stack_b->node->next)
		return ;
	temp_node = stack_b->node;
	stack_b->node = temp_node->next;
	current_node = stack_b->node;
	while (current_node->next != NULL)
	{
		current_node = current_node->next;
	}
	current_node->next = temp_node;
	temp_node->next = NULL;
	if (print == TRUE)
		write(1, "rb\n", 3);
}

void	rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print)
{
	if (!stack_a || !stack_b)
		return ;
	rotate_a(stack_a, FALSE);
	rotate_b(stack_b, FALSE);
	if (print == TRUE)
		write(1, "rr\n", 3);
}
