/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:24:09 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:34 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*x sa : swap a - swap the first 2 elements at the top of stack a. Do nothing 
if there is only one or no elements).
x sb : swap b - swap the first 2 elements at the top of stack b. Do nothing 
if there is only one or no elements).
x ss : sa and sb at the same time.
x pa : push a - take the first element at the top of b and put it at the 
top of a. Do nothing if b is empty.
x pb : push b - take the first element at the top of a and put it at the 
top of b. Do nothing if a is empty.
x ra : rotate a - shift up all elements of stack a by 1. The first element 
becomes
the last one.
x rb : rotate b - shift up all elements of stack b by 1. The first element 
becomes the last one.
x rr : ra and rb at the same time.
x rra : reverse rotate a - shift down all elements of stack a by 1. 
The last element becomes the first one.
x rrb : reverse rotate b - shift down all elements of stack b by 1. 
The last element becomes the first one.
rrr : rra and rrb at the same time.
*/
#include "../include/push_swap.h"

void	swap_first_two(t_stack *stack, char list_name)
{
	int		tmp;

	if (stack->top->prev == NULL)
		return ;
	tmp = stack->top->value;
	stack->top->value = stack->top->prev->value;
	stack->top->prev->value = tmp;
	if (list_name == 'a')
		write(1, "sa\n", 3);
	else if (list_name == 'b')
		write(1, "sb\n", 3);
}

void	rotate(t_stack *stack, char list_name)
{
	int		tmp;
	t_node	*node;

	node = stack->top;
	if (!stack)
		return ;
	tmp = stack->top->value;
	while (node->prev != NULL)
	{
		node->value = node->prev->value;
		node = node->prev;
	}
	stack->bottom->value = tmp;
	if (list_name == 'a')
		write(1, "ra\n", 3);
	else if (list_name == 'b')
		write(1, "rb\n", 3);
}

void	rev_rotate(t_stack *stack, char list_name)
{
	int		tmp;
	t_node	*node;

	node = stack->top;
	if (!stack)
		return ;
	tmp = stack->bottom->value;
	node = stack->bottom;
	while (node->next != NULL)
	{
		node->value = node->next->value;
		node = node->next;
	}
	stack->top->value = tmp;
	if (list_name == 'a')
		write(1, "rra\n", 4);
	else if (list_name == 'b')
		write(1, "rrb\n", 4);
}

void	push(t_stack *stack_src, t_stack *stack_dst, int value, char dst_name)
{
	stack_push_top(stack_dst, value, dst_name);
	stack_pop_top(stack_src);
}
