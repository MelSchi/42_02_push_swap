/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_sort_few.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 17:48:14 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:49 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Puts bigger number in first position and then rotates it down. */
void	sort_few_asc(t_stack *stack)
{
	struct s_list	var;
	t_node			*node;

	var.min = find_smallest(stack);
	var.max = find_biggest(stack);
	node = stack->top;
	while (check_if_sorted_asc(stack) != 1)
	{
		if (node->value == var.min || node->value > stack->bottom->value)
			rotate(stack, 'a');
		else if (node->value == var.max && node->prev->value == var.min)
			rotate(stack, 'a');
		else if (node->value > node->prev->value)
			swap_first_two(stack, 'a');
		else if (node->value < stack->bottom->value)
		{
			rev_rotate(stack, 'a');
			swap_first_two(stack, 'a');
		}
	}
}

/*	Puts lower number in first position and rotates it down. */
void	sort_few_desc(t_stack *stack)
{
	struct s_list	var;
	t_node			*node;

	var.min = find_smallest(stack);
	var.max = find_biggest(stack);
	node = stack->top;
	while (check_if_sorted_desc(stack) != 1)
	{
		if (node->value == var.max || node->value < stack->bottom->value)
			rotate(stack, 'b');
		else if (node->value == var.min && node->prev->value == var.max)
			rotate(stack, 'b');
		else if (node->value < node->prev->value)
			swap_first_two(stack, 'b');
		else if (node->value > stack->bottom->value)
		{
			rev_rotate(stack, 'b');
			swap_first_two(stack, 'b');
		}
	}
}

/*	Sorts in 1 stack if fewer 4 elements else in 2 stacks and 2 buckets. */
void	sort_less_ten(t_stack *stack_a, t_stack *stack_b, int num_elem)
{
	if (num_elem <= 3)
		sort_few_asc(stack_a);
	else
	{
		move_bucket_to_b(stack_a, stack_b, (num_elem / 2));
		sort_few_asc(stack_a);
		sort_few_desc(stack_b);
		while (stack_b->top != NULL)
			push(stack_b, stack_a, stack_b->top->value, 'a');
	}
	free_all(stack_a, stack_b);
	exit(1);
}
