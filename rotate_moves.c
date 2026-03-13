/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:55:20 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:45:21 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	cost;

	if (cost_a < cost_b)
	{
		cost = cost_a;
		while (cost-- > 0)
			reverse_rotate_ab(a, b);
		cost = cost_b - cost_a;
		while (cost-- > 0)
			reverse_rotate_b(b);
	}
	else
	{
		cost = cost_b;
		while (cost-- > 0)
			reverse_rotate_ab(a, b);
		cost = cost_a - cost_b;
		while (cost-- > 0)
			reverse_rotate_a(a);
	}
}

void	rr_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	cost;

	if (cost_a < cost_b)
	{
		cost = cost_a;
		while (cost-- > 0)
			rotate_ab(a, b);
		while (cost_b-- > cost_a)
			rotate_b(b);
	}
	else
	{
		cost = cost_b;
		while (cost-- > 0)
			rotate_ab(a, b);
		while (cost_a-- > cost_b)
			rotate_a(a);
	}
}

void	rra_rb_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	cost;

	cost = cost_a;
	while (cost > 0)
	{
		reverse_rotate_a(a);
		cost --;
	}
	cost = cost_b;
	while (cost > 0)
	{
		rotate_b(b);
		cost --;
	}
}

void	rrb_ra_moves(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	int	cost;

	cost = cost_b;
	while (cost > 0)
	{
		reverse_rotate_b(b);
		cost --;
	}
	cost = cost_a;
	while (cost > 0)
	{
		rotate_a(a);
		cost --;
	}
}

void	rotate_for_push_a(t_stack **a, t_stack **b, t_stack *node)
{
	int	len_a;
	int	len_b;
	int	post_a;
	int	post_b;

	post_b = node->post;
	post_a = node->target_pos;
	len_a = stack_size(a);
	len_b = stack_size(b);
	if (post_a > len_a / 2 && post_b > len_b / 2)
		rrr_moves(a, b, node->cost_a, node->cost_b);
	else if (post_a <= len_a / 2 && post_b <= len_b / 2)
		rr_moves(a, b, node->cost_a, node->cost_b);
	else if (post_a > len_a / 2 && post_b <= len_b / 2)
		rra_rb_moves(a, b, node->cost_a, node->cost_b);
	else
		rrb_ra_moves(a, b, node->cost_a, node->cost_b);
}
