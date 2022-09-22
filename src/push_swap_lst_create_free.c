/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_lst_create_free.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:10:51 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:14 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Creates a list element.*/
t_node	*node_create(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

/*	Creates a list.*/
t_stack	*stack_create(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->bottom = NULL;
	stack->top = NULL;
	return (stack);
}

/*	Removes and frees the first element of a stack. */
int	stack_pop_top(t_stack *stack)
{
	t_node	*temp;

	if (stack->top == NULL)
		return (-1);
	if (stack->top->next == NULL && stack->top->prev == NULL)
	{
		temp = stack->top;
		stack->top = NULL;
		stack->bottom = NULL;
		free(temp);
		return (0);
	}
	temp = stack->top;
	stack->top = stack->top->prev;
	stack->top->next = NULL;
	free(temp);
	return (0);
}

/*	Frees the nodes and of both stacks and the stacks. */
void	free_all(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->top != NULL)
		stack_pop_top(stack_a);
	free(stack_a);
	while (stack_b->top != NULL)
		stack_pop_top(stack_b);
	free(stack_b);
}

/*	Returns the number of elements in a list*/
int	ft_lstsize(t_node *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->prev;
		size++;
	}
	return (size);
}
