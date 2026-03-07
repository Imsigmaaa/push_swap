/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:04:46 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 03:33:28 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	recount_post(t_stack **stack)
{
	int		i;
	t_stack	*new;

	new = *stack;
	i = 0;
	while (new)
	{
		new->post = i;
		i ++;
		new = new->next;
	}
}

void	sort_b(t_stack **st_b)
{
	int		len;
	t_stack	*big;

	len = count_len(st_b);
	big = find_biggest_value(st_b);
	recount_post(st_b);
	if (big->post <= len / 2)
	{
		while (big->post > 0)
		{
			rotate_b(st_b);
			big->post --;
		}
	}
	else
	{
		while (len - big->post > 0)
		{
			reverse_rotate_b(st_b);
			len --;
		}
	}
}
void	recount_target_pos(t_stack **st_a, t_stack **st_b)
{
	t_stack	*temp;
	t_stack	*target_b;
	
	temp = *st_a;
	while (temp)
	{
		target_b = find_target_b(temp->index, st_b);
		temp->target_pos = target_b->post;
		temp = temp->next;
	}
	
}
void	recount_cost(t_stack **st_a, t_stack **st_b)
{
	int	len_a;
	int	len_b;
	t_stack	*temp;

	temp = *st_a;
	len_a = count_len(st_a);
	len_b = count_len(st_b);
	while (temp)
	{
		if(temp->post <= len_a/2)
			temp->cost_a = temp->post;
		else
			temp->cost_a =len_a - temp->post;
		if(temp->target_pos <= len_b/2)
			temp->cost_b = temp->target_pos;
		else
			temp->cost_b =len_b - temp->target_pos;
		temp = temp->next;
	}
}

void	push_swap(t_stack **st_a, t_stack **st_b)
{
	t_stack	*node;

	push_b(st_a, st_b);
	push_b(st_a, st_b);
	while (*st_a)
	{
		recount_post(st_a);
		recount_post(st_b);
		recount_target_pos(st_a, st_b);
		recount_cost(st_a, st_b);
		node = find_best_node(st_a, st_b);
		print_ab(st_a, st_b, node);
		if(*st_a)
			push_b(st_a, st_b);
	}
	sort_b(st_b);
	while (*st_b)
		push_a(st_a, st_b);
}
