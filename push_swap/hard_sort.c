/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hard_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:31:08 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/10 13:29:58 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter_2(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;

	first = stack_a->node;
	second = stack_a->node->next;
	if (second->index < first->index)
		swap_a(stack_a, TRUE);
}

void	sorter_3(t_stack *stack_a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	first = stack_a->node;
	second = stack_a->node->next;
	third = stack_a->node->next->next;
	if (is_sorted(stack_a) == TRUE)
		return ;
	else if (first->index < second->index && first->index < third->index)
	{
		swap_a(stack_a, TRUE);
		rotate_a(stack_a, TRUE);
	}
	else if (second->index > first->index)
		reverse_rot_a(stack_a, TRUE);
	else if (first->index > second->index && first->index > third->index)
	{
		rotate_a(stack_a, TRUE);
		if (second->index > third->index)
			swap_a(stack_a, TRUE);
	}
	else
		swap_a(stack_a, TRUE);
}

void	sorter_4(t_stack *stack_a, t_stack *stack_b)
{
	size_t	mov;
	size_t	min;

	min = get_min(stack_a);
	mov = mov_cost_ra(stack_a, min);
	if (is_sorted(stack_a) == TRUE)
		return ;
	while (stack_a->node->index != min)
	{
		if (mov > 1)
			reverse_rot_a(stack_a, TRUE);
		else
			rotate_a(stack_a, TRUE);
	}
	push_b(stack_a, stack_b, TRUE);
	sorter_3(stack_a);
	push_a(stack_a, stack_b, TRUE);
}

void	sorter_5(t_stack *stack_a, t_stack *stack_b)
{
	size_t	mov;
	size_t	min;

	min = get_min(stack_a);
	mov = mov_cost_ra(stack_a, min);
	if (is_sorted(stack_a) == TRUE)
		return ;
	while (stack_a->node->index != min)
	{
		if (mov > 3)
			reverse_rot_a(stack_a, TRUE);
		else
			rotate_a(stack_a, TRUE);
	}
	push_b(stack_a, stack_b, TRUE);
	sorter_4(stack_a, stack_b);
	push_a(stack_a, stack_b, TRUE);
}
