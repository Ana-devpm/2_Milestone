/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:44:12 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 09:47:33 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a)
{
	t_node	*fst_node;
	t_node	*sec_node;

	if (!stack_a || !stack_a->node || !stack_a->node->next)
		return (1);
	fst_node = stack_a->node;
	sec_node = fst_node->next;
	fst_node->next = sec_node->next;
	sec_node->next = fst_node;
	stack_a->node = sec_node;
}

void	swap_b(t_stack *stack_b)
{
	t_node	*fst_node;
	t_node	*sec_node;

	if (!stack_b || !stack_b->node || !stack_b->node->next)
		return (1);
	fst_node = stack_b->node;
	sec_node = fst_node->next;
	fst_node->next = sec_node->next;
	sec_node->next = fst_node;
	stack_b->node = sec_node;
}

void	doble_swap(t_stacks *stacks)
{
	if (!stacks)
		return (1);
	swap_a(&stacks->stack_a);
	swap_b(&stacks->stack_b);
}
