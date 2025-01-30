/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:11:11 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 09:52:27 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef int	t_bool;
# define TRUE 0 
# define FALSE 1

# define ARG_ERR_MSG "Error.\n"

typedef struct	s_node
{
	size_t			index;
	int				nbr;
	struct s_node	*next;
}	t_node;

typedef struct	s_stack
{
	size_t	size;
	t_node	*node;
}	t_stack;

typedef	struct	s_stacks
{
	t_stack		stack_a;
	t_stack		stack_b;
}	t_stacks;

void		stack_clean(t_node **node);
t_node		*lst_malloc_node(int nbr);
t_bool		stack_check_dups(t_stack stack_a);
t_bool		check_numbers(int argc, char **argv);
t_bool		malloc_number_to_stack(t_stack	*stack, int nbr);

#endif