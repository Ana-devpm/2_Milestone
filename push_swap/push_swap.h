/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 16:11:11 by afailde-          #+#    #+#             */
/*   Updated: 2025/02/18 20:36:27 by afailde-         ###   ########.fr       */
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

//This are the different moves available//

void		swap_a(t_stack *stack_a, t_bool	print);
void		swap_b(t_stack *stack_b, t_bool print);
void		doble_swap(t_stacks *stacks, t_bool print);
void		push_a(t_stack	*stack_a, t_stack *stack_b, t_bool print);
void		push_b(t_stack *stack_a, t_stack *stack_b, t_bool print);
void		rotate_a(t_stack *stack_a, t_bool print);
void		rotate_b(t_stack *stack_b, t_bool print);
void		rotate_both(t_stack *stack_a, t_stack *stack_b, t_bool print);
void		reverse_rot_a(t_stack *stack_a, t_bool print);
void		reverse_rot_b(t_stack *stack_b, t_bool print);
void		reverse_rot_both(t_stacks *stacks, t_bool print);

//Different sorter scripts//

t_bool		is_sorted(t_stack *stack_a);
void		sorter(t_stacks *stacks, size_t size);
void		sorter_2(t_stack *stack_a);
void		sorter_3(t_stack *stack_a);
void		sorter_4(t_stack *stack_a, t_stack *stack_b);
void		sorter_5(t_stack *stack_a, t_stack *stack_b);


t_node		*lst_malloc_node(int nbr);
t_bool		stack_check_dups(t_stack stack_a);
t_bool		check_numbers(int argc, char **argv);
t_bool		malloc_number_to_stack(t_stack	*stack, int nbr);


size_t	get_min(t_stack *stack);
size_t	mov_cost_ra(t_stack	*stack, size_t index);

#endif