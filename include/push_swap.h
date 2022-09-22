/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mschiman <mschiman@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 16:13:44 by mschiman          #+#    #+#             */
/*   Updated: 2022/01/15 13:30:38 by mschiman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	t_node			*bottom;
	t_node			*top;
}	t_stack;

typedef struct s_list
{
	long	res;
	int		sign;
	int		num_elem;
	int		b_start;
	int		b_end;
	int		b_size;
	int		amount_buckets;
	int		more_memb;
	int		max_check;
	int		max;
	int		min;
	int		sorted;
	int		i;
	int		j;
	int		k;
	int		count;
}	t_list;

void	ft_print_err(void);
int		ft_atoi(const char *nptr, t_stack *stack);
void	check_input(t_stack *stack);
int		find_smallest(t_stack *stack);
int		find_biggest(t_stack *stack);
int		find_bucket_end(t_stack *stack, int bkt_size);
int		more_memb(t_stack *stack, int b_start, int b_end, int b_size);
int		amount_buckets(int num_elem);
int		find_position(t_stack *stack, int nb);
int		check_if_sorted_asc(t_stack *stack);
int		check_if_sorted_desc(t_stack *stack);
void	swap_first_two(t_stack *stack, char list_name);
void	rotate(t_stack *stack, char list_name);
void	rev_rotate(t_stack *stack, char list_name);
t_node	*node_create(int value);
t_stack	*stack_create(void);
int		stack_push_top(t_stack *stack, int value, char list_name);
int		stack_push_bottom(t_stack *stack, int value);
void	push(t_stack *stack_src, t_stack *stack_dst, int value, char dst_name);
int		stack_pop_top(t_stack *stack);
int		ft_lstsize(t_node *lst);
void	sort_few_asc(t_stack *stack);
void	sort_few_desc(t_stack *stack);
void	sort_less_ten(t_stack *stack_a, t_stack *stack_b, int num_elem);
void	fill_b(t_stack *stack_a, t_stack *stack_b, int num_elem);
void	move_bucket_to_b(t_stack *stack_a, t_stack *stack_b, int b_size);
void	sort_back_to_a(t_stack *stack_a, t_stack *stack_b);
void	free_all(t_stack *stack_a, t_stack *stack_b);

#endif
