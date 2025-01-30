/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:29:57 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 09:44:09 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	check_numbers(int argc, char **argv)
{
	int		i_c;
	int		i_v;

	i_c = 1;
	while (i_c < argc)
	{
		i_v = 0;
		if (argv[i_c][i_v] == '\0')
			return (FALSE);
		while (argv[i_c][i_v] != '\0')
		{
			if ((argv[i_c][i_v] == '+' || argv[i_c][i_v] == '-')
			&& argv[i_c][i_v + 1] != '\0' && ft_isdigit(argv[i_c][i_v + 1]))
				i_v++;
			if (ft_isdigit(argv[i_c][i_v]) && (argv[i_c][i_v + 1] == '+'
			|| argv[i_c][i_v + 1] == '-'))
				return (FALSE);
			if (!ft_isdigit(argv[i_c][i_v]) && argv[i_c][i_v] != ' ')
				return (FALSE);
			i_v++;
		}
		i_c++;
	}
	return (TRUE);
}

t_bool	stack_check_dups(t_stack stack_a)
{
	t_node	*node_iter;
	t_node	*tmp_node;

	node_iter = stack_a.node;
	while (node_iter != NULL && node_iter->next != NULL)
	{
		tmp_node = node_iter->next;
		while (tmp_node != NULL)
		{
			if (node_iter->nbr == tmp_node->nbr)
			{
				return (FALSE);
			}
			tmp_node = tmp_node->next;
		}
		node_iter = node_iter->next;
	}
}
