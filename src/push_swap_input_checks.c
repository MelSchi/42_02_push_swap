/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 14:35:30 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 15:57:56 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/*Checks if the input is only numbers. If yes converts, if not shows error.*/
int	ft_atoi(const char *nptr, t_stack *stack)
{
	t_list	var;

	var.res = 0;
	var.sign = 1;
	if (*nptr == '-')
	{
		var.sign = -1;
		nptr++;
	}
	while (*nptr != '\0')
	{
		if (!(*nptr >= '0' && *nptr <= '9'))
		{
			ft_print_err();
			free(stack);
		}
		var.res = (var.res * 10) + (*nptr - '0');
		nptr++;
	}
	if (var.sign * var.res >= -2147483648 && var.sign * var.res <= 2147483647)
		return (var.sign * var.res);
	write(2, "Error\n", 6);
	free(stack);
	exit(EXIT_FAILURE);
}

void	ft_print_err(void)
{
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

static void	check_duplicates(t_stack *stack)
{
	t_node			*node;
	t_node			*compare;

	node = stack->top;
	compare = node->prev;
	while (node != NULL)
	{
		while (compare != NULL)
		{
			if (node->value == compare->value)
				ft_print_err();
			else
				compare = compare->prev;
		}
		node = node->prev;
		if (node != NULL)
			compare = node->prev;
	}
}

void	check_input(t_stack *stack)
{
	if (check_if_sorted_asc(stack) == 1)
		exit(0);
	check_duplicates(stack);
}
