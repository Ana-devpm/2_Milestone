/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 18:44:12 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/03 16:18:35 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack *stack_a, t_bool	print)
{
	t_node	*fst_node;
	t_node	*sec_node;

	if (!stack_a || !stack_a->node || !stack_a->node->next)
		return ;
	fst_node = stack_a->node;
	sec_node = fst_node->next;
	fst_node->next = sec_node->next;
	sec_node->next = fst_node;
	stack_a->node = sec_node;
	if (print == TRUE)
		write(1, "sa\n", 3);
}

void	swap_b(t_stack *stack_b, t_bool print)
{
	t_node	*fst_node;
	t_node	*sec_node;

	if (!stack_b || !stack_b->node || !stack_b->node->next)
		return ;
	fst_node = stack_b->node;
	sec_node = fst_node->next;
	fst_node->next = sec_node->next;
	sec_node->next = fst_node;
	stack_b->node = sec_node;
	if (print == TRUE)
		write(1, "sb\n", 3);

}

void	doble_swap(t_stacks *stacks, t_bool print)
{
	if (!stacks)
		return ;
	swap_a(&stacks->stack_a, FALSE);
	swap_b(&stacks->stack_b, FALSE);
	if (print == TRUE)
		write(1, "ss\n", 3);
}
