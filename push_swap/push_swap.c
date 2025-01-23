/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:32:49 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/23 18:22:36 by afailde-         ###   ########.fr       */
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
		if ((sign == 1 && temp_result > (long)INT_MAX) ||
		(sign == -1 && -temp_result < (long)INT_MIN))
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
				return (FALSE);
			
		}
		arg_index++;
	}
	return (TRUE);
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
		if (malloc_fill_stack(&(stacks.stack_a), argc, argv) == FALSE)
			return (printf("jajasalu2\n"), 1);
		printf("Todo ok\n");
	}
	else
		printf("Error\n");
	return (0);
}
