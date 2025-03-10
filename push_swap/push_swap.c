/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:32:49 by afailde-          #+#    #+#             */
/*   Updated: 2025/03/10 16:46:46 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	ft_atoi_check(const char *str, int *result, int *str_index)
{
	int					sign;
	long				temp_result;

	sign = 1;
	temp_result = 0;
	while (ft_isspace(str[*str_index]))
		*str_index = *str_index + 1;
	if (str[*str_index] == '-')
		sign = -1;
	if (str[*str_index] == '+' || str[*str_index] == '-')
		*str_index = *str_index + 1;
	while (ft_isdigit(str[*str_index]))
	{
		temp_result = (temp_result * 10) + str[*str_index] - '0';
		if ((sign == 1 && temp_result > (long)INT_MAX)
			|| (sign == -1 && - temp_result < (long)INT_MIN))
			return (FALSE);
		*str_index = *str_index + 1;
	}
	*result = temp_result * sign;
	return (TRUE);
}

/**
 * @warning MALLOC
 */
t_bool	malloc_fill_stack(t_stack	*stack_a, int argc, char **argv)
{
	int		arg_index;
	int		str_index;
	int		temp_nbr;

	arg_index = 1;
	while (arg_index < argc)
	{
		str_index = 0;
		while (argv[arg_index][str_index])
		{
			if (ft_atoi_check(argv[arg_index], &temp_nbr, &str_index) == FALSE)
				return (stack_clean(&stack_a->node), FALSE);
			if (malloc_number_to_stack(stack_a, temp_nbr) == FALSE)
				return (stack_clean(&stack_a->node), FALSE);
		}
		arg_index++;
	}
	return (TRUE);
}

static t_bool	indexer(t_stacks stacks)
{
	t_node	*current_node;
	t_node	*compare_node;
	size_t	index;

	if (!stacks.stack_a.node || !stacks.stack_a.size)
		return (FALSE);
	current_node = stacks.stack_a.node;
	while (current_node)
	{
		index = 0;
		compare_node = stacks.stack_a.node;
		while (compare_node)
		{
			if (compare_node->nbr < current_node->nbr)
				index++;
			compare_node = compare_node->next;
		}
		current_node->index = index;
		current_node = current_node->next;
	}
	stacks.stack_a.size = index + 1;
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (printf(ARG_ERR_MSG), 1);
	stacks.stack_a.node = NULL;
	stacks.stack_a.size = 0;
	stacks.stack_b.node = NULL;
	stacks.stack_b.size = 0;
	if (check_numbers(argc, argv) == TRUE)
	{
		if (malloc_fill_stack(&(stacks.stack_a), argc, argv) == FALSE)
			return (printf("Error\n"), 1);
		if (stack_check_dups(stacks.stack_a) == FALSE || indexer(stacks))
			return (stack_clean(&stacks.stack_a.node), printf("Error\n"), 1);
	}
	else
		return (printf("Error\n"), 1);
	if (is_sorted(&stacks.stack_a) == FALSE)
		sorter(&stacks, stacks.stack_a.size);
	stack_clean(&stacks.stack_a.node);
	stack_clean(&stacks.stack_b.node);
	return (0);
}
