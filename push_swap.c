/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:04:46 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/04 23:01:16 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lesscost_node_a_zero(t_stack **stack_b,t_stack *lesscost_node_a, t_stack *target_b)
{
	int	post_a;
	int post_b;
	int i;
	int times;
	int stack_b_len;

	i = 0;
	post_a = lesscost_node_a->post;
	post_b = target_b->post;
	stack_b_len = count_len(stack_b);
	if (post_b == 1)
		i += swap_b(stack_b);
	else if (post_b  > stack_b_len / 2)
		{
			times = i + stack_b_len - post_b;
			while (i < times)
				i += reverse_rotate_b(stack_b);
		}
		else
		{
			times = i + post_b;
			while (i < times)
				i += rotate_b(stack_b);
		}
		return (i);
	}

int	target_b_zero(t_stack **stack_a,t_stack *lesscost_node_a, t_stack *target_b)
{
	int	post_a;
	int post_b;
	int i;
	int times;
	int stack_a_len;

	i = 0;
	post_a = lesscost_node_a->post;
	post_b = target_b->post;
	stack_a_len = count_len(stack_a);
	if (post_a == 1)
		i += swap_a(stack_a);
	else if (post_a  > stack_a_len / 2)
	{
		times = i + stack_a_len - post_a;
		while (i < times)
			i += reverse_rotate_a(stack_a);
	}
	else
	{
		times = i + post_a;
		while (i < times)
			i += rotate_a(stack_a);
	}
	return (i);
}

int	stack_ab_rrr(t_stack **stack_a, t_stack **stack_b, t_stack *lesscost_node_a, t_stack *target_b)
{
	int i;
	int times;

	i = 0;
	if (count_len(stack_a) - lesscost_node_a->post >= count_len(stack_b) - target_b->post)
	{
		times =count_len(stack_a) - lesscost_node_a->post + i;
		while (i < times)
			i += reverse_rotate_ab(stack_a, stack_b);
		times  =count_len(stack_a) -  lesscost_node_a->post -count_len(stack_b)+ target_b->post + i;
		while (i < times)
			i += reverse_rotate_a(stack_a);
	}
	else
	{
		times = count_len(stack_b) - target_b->post + i;
		while (i <times)
			i += reverse_rotate_ab(stack_a, stack_b);
		times = count_len(stack_b) - target_b->post - count_len(stack_a) + target_b->post + i;
		while (i < times)
			i += reverse_rotate_b(stack_b);
	}
	return (i);
}

int	stack_ab_rr(t_stack **stack_a, t_stack **stack_b, t_stack *lesscost_node_a, t_stack *target_b)
{
	
	int i;
	int times;

	i = 0;
	if (lesscost_node_a->post >= target_b->post)
	{
		times = lesscost_node_a->post + i;
		while (i < times)
			i += rotate_ab(stack_a, stack_b);
		times  = lesscost_node_a->post - target_b->post + i;
		while (i < times)
			i += rotate_a(stack_a);
	}
	else
	{
		times = target_b->post + i;
		while (i < times)
			i += rotate_ab(stack_a, stack_b);
		times = target_b->post - lesscost_node_a->post + i;
		while (i < times)
			i += rotate_b(stack_b);
	}
	return (i);
}

int rra_and_rb(t_stack **stack_a, t_stack **stack_b, t_stack *lesscost_node_a, t_stack *target_b)
{
	int	post_a;
	int post_b;
	int	i;
	int times;

	post_a = lesscost_node_a->post;
	post_b = target_b->post;
	times = i + count_len(stack_a) - post_a;
	while (i < times)
		i += reverse_rotate_a(stack_a);
	times = i + post_b;
	while (i < times )
		i += rotate_b(stack_b);
}

int rrb_and_ra(t_stack **stack_a, t_stack **stack_b, t_stack *lesscost_node_a, t_stack *target_b)
{
	int	post_a;
	int post_b;
	int	i;
	int times;

	post_a = lesscost_node_a->post;
	post_b = target_b->post;
	times = i + count_len(stack_b) - post_b;
	while (i < times)
		i += reverse_rotate_b(stack_b);
	times = i + post_a;
	while (i < times )
		i += rotate_a(stack_a);
	return (i);
}

int	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int time;
	t_stack *lesscost_node_a;
	t_stack *target_b;
	
	i = 0;
	time = 0;
	while (*stack_a)
	{
		lesscost_node_a = find_lesscost_node_a(stack_a, stack_b);
		target_b = find_littlebigger_value(lesscost_node_a->index, stack_b);
		if(lesscost_node_a->post == 0 && target_b->post == 0)
			i += push_b(stack_a, stack_b);
		else if(lesscost_node_a->post == 0)
			i += lesscost_node_a_zero(stack_b, target_b, lesscost_node_a);
		else if (target_b->post == 0)
			i = target_b_zero(stack_a, lesscost_node_a, target_b);
		else
		{
			if(lesscost_node_a->post > count_len(stack_a) / 2 && target_b->post > count_len(stack_b) / 2)
				i += stack_ab_rrr(stack_a, stack_b, lesscost_node_a, target_b);
			else if (lesscost_node_a->post <= count_len(stack_a) / 2 && target_b->post <= count_len(stack_b) / 2)
				i += stack_ab_rr(stack_a, stack_b, lesscost_node_a, target_b);
			else if (lesscost_node_a->post > count_len(stack_a) / 2 && target_b->post <= count_len(stack_b) / 2)
				i += rra_and_rb(stack_a, stack_b, lesscost_node_a, target_b);
			else
				i += rrb_and_ra(stack_a, stack_b, lesscost_node_a, target_b);
		}
		i += push_b(stack_a, stack_b);
	}
}