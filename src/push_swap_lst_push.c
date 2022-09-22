/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_push.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 12:41:37 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:25 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Creates a node and puts it on top of a stack. */
int	stack_push_top(t_stack *stack, int value, char list_name)
{
	t_node	*node;

	node = node_create(value);
	node->prev = stack->top;
	stack->top = node;
	if (!node->prev)
	{
		if (stack->bottom != NULL)
			return (-1);
		stack->bottom = node;
	}
	else
		node->prev->next = node;
	if (list_name == 'a')
		write(1, "pa\n", 3);
	else if (list_name == 'b')
		write(1, "pb\n", 3);
	return (0);
}

/*	Creates a node and puts it on the bottom of a stack. */
int	stack_push_bottom(t_stack *stack, int value)
{
	t_node	*node;

	node = node_create(value);
	if (!node)
		return (-1);
	node->next = stack->bottom;
	stack->bottom = node;
	if (!node->next)
	{
		if (stack->top != NULL)
			return (-1);
		stack->top = node;
	}
	else
		node->next->prev = node;
	return (0);
}
