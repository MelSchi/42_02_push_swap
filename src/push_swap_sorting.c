/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sorting.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:55:30 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:56 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Returns where more bucket members are located 1 = upper half
*	2 = lower half of the stack*/
int	more_memb(t_stack *stack, int b_start, int b_end, int b_size)
{
	struct s_list	var;
	t_node			*node;

	var.count = 0;
	var.k = 0;
	var.num_elem = ft_lstsize(stack->top);
	if (var.num_elem % 2 == 0)
		var.max_check = var.num_elem / 2;
	else
		var.max_check = (var.num_elem / 2) + 1;
	node = stack->top;
	while (var.k != var.max_check)
	{
		if (node->value >= b_start && node->value < b_end)
			var.count++;
		node = node->prev;
		var.k++;
	}
	if (var.count >= (b_size / 2))
		return (1);
	return (2);
}

/*	Finds bucket members and moves them to stack b. Rotates in the direction
*	where more members have been found. */
void	move_bucket_to_b(t_stack *stack_a, t_stack *stack_b, int b_size)
{
	struct s_list	var;
	t_node			*node_a;

	var.k = 0;
	var.b_start = find_smallest(stack_a);
	var.b_end = find_bucket_end(stack_a, b_size);
	var.more_memb = more_memb(stack_a, var.b_start, var.b_end, b_size);
	while (var.k != b_size)
	{
		node_a = stack_a->top;
		if (node_a->value >= var.b_start && node_a->value <= var.b_end)
		{
			push(stack_a, stack_b, stack_a->top->value, 'b');
			var.k++;
		}
		else
		{
			if (var.more_memb == 1)
				rotate(stack_a, 'a');
			else
				rev_rotate(stack_a, 'a');
		}
	}
}

/*	Calls the functions to move elements in buckets to b.*/
void	fill_b(t_stack *stack_a, t_stack *stack_b, int num_elem)
{
	struct s_list	var;

	var.i = 0;
	var.amount_buckets = amount_buckets(num_elem);
	var.b_size = (num_elem / var.amount_buckets);
	while (var.i != var.amount_buckets)
	{
		if (var.i == (var.amount_buckets - 1))
			var.b_size = ft_lstsize(stack_a->top);
		move_bucket_to_b(stack_a, stack_b, var.b_size);
		var.i++;
	}
}

/*	Finds the biggest elem in b and rotates it to the top with the fewest
*	movements depending on it's position. Then pushes it to a. */
void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	struct s_list	var;

	var.i = ft_lstsize(stack_b->top);
	while (var.i > 0)
	{
		var.max = find_biggest(stack_b);
		var.num_elem = ft_lstsize(stack_b->top);
		if (find_position(stack_b, var.max) <= (var.num_elem / 2))
		{
			while (stack_b->top->value != var.max)
				rotate(stack_b, 'b');
		}
		else
		{
			while (stack_b->top->value != var.max)
				rev_rotate(stack_b, 'b');
		}
		push(stack_b, stack_a, stack_b->top->value, 'a');
		var.i--;
	}
}
