/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_infos.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 11:52:46 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:20 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Returns the smallest number of the stack */
int	find_smallest(t_stack *stack)
{
	struct s_list	var;
	t_node			*node;

	if (!stack)
		exit(EXIT_FAILURE);
	var.min = stack->top->value;
	node = stack->top;
	while (node != NULL)
	{
		if (node->value < var.min)
		{
			var.min = node->value;
			node = stack->top;
		}
		else
			node = node->prev;
	}
	return (var.min);
}

/*	Returns the biggest number of the stack */
int	find_biggest(t_stack *stack)
{
	struct s_list	var;
	t_node			*node;

	if (!stack)
		exit(EXIT_FAILURE);
	node = stack->top;
	var.max = stack->top->value;
	while (node != NULL)
	{
		if (node->value > var.max)
		{
			var.max = node->value;
			node = stack->top;
		}
		else
			node = node->prev;
	}
	return (var.max);
}

/*	Returns the position of a number in a stack counted from the top.
*	Returns 0 if not found. */
int	find_position(t_stack *stack, int nb)
{
	int		i;
	t_node	*node;

	if (!stack || !nb)
		return (-1);
	i = 1;
	node = stack->top;
	while (node != NULL)
	{
		if (node->value == nb)
			return (i);
		node = node->prev;
		i++;
	}
	return (0);
}

int	check_if_sorted_asc(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (-1);
	node = stack->top;
	while (node ->prev != NULL && node->value < node->prev->value)
	{
		node = node->prev;
		if (node->prev == NULL)
			return (1);
	}
	return (0);
}

int	check_if_sorted_desc(t_stack *stack)
{
	t_node	*node;

	if (!stack)
		return (-1);
	node = stack->top;
	while (node ->prev != NULL && node->value > node->prev->value)
	{
		node = node->prev;
		if (node->prev == NULL)
			return (1);
	}
	return (0);
}
