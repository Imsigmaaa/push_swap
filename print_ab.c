/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:55:20 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/09 05:51:39 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr_moves(t_stack **st_a, t_stack **st_b, int cost_a, int cost_b)
{
	int cost;

	if (cost_a < cost_b)
	{
		cost = cost_a;
		while (cost-- > 0)
			reverse_rotate_ab(st_a, st_b);
		cost = cost_b - cost_a;
		while (cost-- > 0)
			reverse_rotate_b(st_b);
	}
	else
	{
		cost = cost_b;
		while (cost-- > 0)
			reverse_rotate_ab(st_a, st_b);
		cost = cost_a - cost_b;
		while (cost-- > 0)
			reverse_rotate_a(st_a);
	}
}

void	rr_moves(t_stack **st_a, t_stack **st_b, int ra, int rb)
{
	int	cost;
	if (ra < rb)
	{
		cost = ra;
		while (cost-- > 0)
			rotate_ab(st_a, st_b);
		while (rb-- > ra)
			rotate_b(st_b);
	}
	else
	{
		cost = rb;
		while (cost-- > 0)
			rotate_ab(st_a, st_b);
		while (ra-- > rb)
			rotate_a(st_a);
	}
}

void	rra_rb_moves(t_stack **st_a, t_stack **st_b, int rra, int rb)
{
	while (rra > 0)
	{
		reverse_rotate_a(st_a);
		rra --;
	}
	while (rb > 0)
	{
		rotate_b(st_b);
		rb --;
	}
}

void	rrb_ra_moves(t_stack **st_a, t_stack **st_b, int ra, int rrb)
{
	
	while (rrb > 0)
	{
		reverse_rotate_b(st_b);
		rrb --;
	}
	while (ra > 0)
	{
		rotate_a(st_a);
		ra --;
	}
}

void	rotate_for_push_b(t_stack **st_a, t_stack **st_b, t_stack *node)
{
	int	len_a;
	int	len_b;
	int	post_a;
	int	post_b;

	post_a = node->post;
	post_b = node->target_pos;
	len_a = count_len(st_a);
	len_b = count_len(st_b);

	if (post_a > len_a / 2 && post_b > len_b / 2)
        rr_moves(st_a, st_b, node->cost_a, node->cost_b);
	else if (post_a <= len_a / 2 && post_b <= len_b / 2)
		rr_moves(st_a, st_b, node->cost_a, node->cost_b);
	else if (post_a > len_a / 2 && post_b <= len_b / 2)
		rra_rb_moves(st_a, st_b, node->cost_a, node->cost_b);
	else
		rrb_ra_moves(st_a, st_b, node->cost_a, node->cost_b);
}

void	rotate_for_push_a(t_stack **st_a, t_stack **st_b, t_stack *node)
{
	int	len_a;
	int	len_b;
	int	post_a;
	int	post_b;

	post_b = node->post;
	post_a = node->target_pos;
	len_a = count_len(st_a);
	len_b = count_len(st_b);

	/*fprintf(stderr, "post_b=%d post_a=%d cost_b=%d cost_a=%d len_b=%d len_a=%d\n",
    post_b, post_a, node->cost_b, node->cost_a, len_b, len_a);*/
	if (post_a > len_a / 2 && post_b > len_b / 2)
		ab_rrr(st_a, st_b, node->cost_a, node->cost_b);
	else if (post_a <= len_a / 2 && post_b <= len_b / 2)
		ab_rr(st_a, st_b, node->cost_a, node->cost_b);
	else if (post_a > len_a / 2 && post_b <= len_b / 2)
		rra_and_rb(st_a, st_b, node->cost_a, node->cost_b);
	else
		rrb_and_ra(st_a, st_b, node->cost_a, node->cost_b);
}
