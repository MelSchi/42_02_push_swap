/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:21:26 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 15:51:20 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	struct s_list	var;

	if (argc <= 2)
		return (-1);
	var.i = 0;
	var.num_elem = (argc - 1);
	stack_a = stack_create();
	while (var.i < var.num_elem)
	{
		var.i++;
		stack_push_bottom(stack_a, ft_atoi(argv[var.i], stack_a));
	}
	check_input(stack_a);
	stack_b = stack_create();
	if (var.num_elem <= 10)
		sort_less_ten(stack_a, stack_b, var.num_elem);
	fill_b(stack_a, stack_b, var.num_elem);
	sort_back_to_a(stack_a, stack_b);
	free_all(stack_a, stack_b);
	return (0);
}
