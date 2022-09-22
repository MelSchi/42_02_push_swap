/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_buckets.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 10:46:23 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 12:47:00 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*	Defines the amount of buckets needed according to the number of elements
*	to sort. These are statistically identified averages. */
int	amount_buckets(int num_elem)
{
	struct s_list	var;

	if (num_elem <= 50)
		var.amount_buckets = 3;
	else if (num_elem <= 300)
		var.amount_buckets = 10;
	else if (num_elem <= 750)
		var.amount_buckets = 13;
	else if (num_elem <= 1000)
		var.amount_buckets = 19;
	else if (num_elem > 1000)
		var.amount_buckets = (num_elem / 50);
	return (var.amount_buckets);
}

/* Finds the end element of a bucket.*/
int	find_bucket_end(t_stack *stack, int bkt_size)
{
	struct s_list	var;
	t_node			*node;
	t_node			*compare;

	var.count = 0;
	node = stack->top;
	compare = stack->top;
	if (!stack || !bkt_size)
		exit(EXIT_FAILURE);
	while (node != NULL && var.count <= bkt_size)
	{
		if (compare->value >= node->value)
			var.count++;
		node = node->prev;
		if (var.count > bkt_size || (node == NULL && var.count != bkt_size))
		{
			node = stack->top;
			compare = compare->prev;
			var.count = 0;
		}
	}
	return (compare->value);
}
