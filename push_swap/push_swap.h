/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:11:11 by afailde-          #+#    #+#             */
/*   Updated: 2025/01/30 16:53:01 by afailde-         ###   ########.fr       */
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

typedef struct s_node
{
	size_t			index;
	int				nbr;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	size_t	size;
	t_node	*node;
}	t_stack;

typedef struct s_stacks
{
	t_stack		stack_a;
	t_stack		stack_b;
}	t_stacks;

void		stack_clean(t_node **node);
void		swap_a(t_stack *stack_a);
void		swap_b(t_stack *stack_b);
void		doble_swap(t_stacks *stacks);
void		push_a(t_stack	*stack_a, t_stack *stack_b);
void		push_b(t_stack *stack_a, t_stack *stack_b);
void		rotate_a(t_stack *stack_a);
void		rotate_b(t_stack *stack_b);
void		rotate_both(t_stacks *stacks);
void		reverse_rot_a(t_stack *stack_a);
void		reverse_rot_b(t_stack *stack_b);
void		reverse_rot_both(t_stacks *stacks);
t_node		*lst_malloc_node(int nbr);
t_bool		is_sorted(t_stack *stack_a);
t_bool		stack_check_dups(t_stack stack_a);
t_bool		check_numbers(int argc, char **argv);
t_bool		malloc_number_to_stack(t_stack	*stack, int nbr);

#endif