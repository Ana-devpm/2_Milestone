/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:32:24 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/18 20:35:51 by afailde-         ###   ########.fr       */
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

void k_sort2(t_stack *stack_a, t_stack *stack_b)
{
	size_t	cost_ra;
	while (stack_b->size != 0)
	{
		cost_ra = mov_cost_ra(stack_b, stack_b->size - 1);
		while (stack_b->node->index != stack_b->size - 1)
		{
			if (cost_ra >= stack_b->size / 2)
				reverse_rot_b(stack_b, TRUE);
			else
				rotate_b(stack_b, TRUE);
		}
		push_a(stack_a, stack_b, TRUE);
	}
}

void k_sort1(t_stack *stack_a, t_stack *stack_b)
{
	size_t	counter;
	size_t	magic_number;

	counter = 0;
	magic_number = ft_squareroot(stack_a->size) * 133 / 100;
	while (stack_a->size != 0)
	{
		if (stack_a->node->index <= counter)
		{
			push_b(stack_a, stack_b, TRUE);
			counter++;
		}
		else if (stack_a->node->index <= counter + magic_number)
		{
			push_b(stack_a, stack_b, TRUE);
			counter++;
			if (stack_a->node->index <= counter + magic_number)
				rotate_b(stack_b, TRUE);
			else
				rotate_both(stack_a, stack_b, TRUE);
		}
		else
			rotate_a(stack_a, TRUE);
	}
	k_sort2(stack_a, stack_b);
}

void	sorter(t_stacks *stacks, size_t size)
{
	if (size == 2)
		sorter_2 (&stacks->stack_a);
	else if (size == 3)
		sorter_3(&stacks->stack_a);
	else if (size == 4)
		sorter_4(&stacks->stack_a, &stacks->stack_b);
	else if (size == 5)
		sorter_5(&stacks->stack_a, &stacks->stack_b);
	else
		k_sort1(&stacks->stack_a, &stacks->stack_b);
}
