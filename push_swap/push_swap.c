/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:32:49 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 16:31:58 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/**
 * @warning MALLOC
 */
t_bool	malloc_number_to_stack(t_stack *stack, int nbr) 
{
	t_node	*new_node;
	t_node	*current_node;

	new_node = lst_malloc_node(nbr);
	if (!new_node)
	{
		printf("Error: No se pudo crear el nodo\n");
		return (FALSE);
	}
	if (stack->node == NULL)
		stack->node = new_node;
	else
	{
		current_node = stack->node;
		while (current_node->next != NULL)
			current_node = current_node->next;
		current_node->next = new_node;
	}
	stack->size++;
	return (TRUE);
}

/**
 * @warning MALLOC
 */
t_bool	malloc_fill_stack(t_stack	*stack_a, int argc, char **argv)
{
	int		index;
	int		str_index;

	index = 1;
	while (index < argc)
	{
		str_index = 0;
		while (argv[index][str_index])
		{
			while (argv[index][str_index] == ' ')
				str_index++;
			
		}
	}
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
	{
		printf("Por favor, pasa una secuencia de números como argumentos.\n");
		return (1);
	}
	stacks.stack_a.node = NULL;
	stacks.stack_b.node = NULL;
	if (check_numbers(argc, argv) == TRUE)
	{
		/*if (malloc_fill_stack(&(stacks.stack_a), argc, argv) == FALSE)
		{
			
		}*/
		printf("Todo ok\n");
	}
	else
		printf("Error\n");
	return (0);
}
