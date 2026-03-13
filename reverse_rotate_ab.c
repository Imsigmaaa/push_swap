/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:37:39 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:29:00 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*node;
	t_stack	*end;

	end = *stack;
	while (end->next->next)
		end = end->next;
	node = end;
	node = node->next;
	end->next = NULL;
	stackadd_front(stack, node);
}

void	reverse_rotate_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	reverse_rotate(a);
	write(1, "rra\n", 4);
	return ;
}

void	reverse_rotate_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	return ;
}

void	reverse_rotate_ab(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	return ;
}
