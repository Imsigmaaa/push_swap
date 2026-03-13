/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:29:16 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:29:09 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack	*node;

	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	stackadd_back(stack, node);
	return ;
}

void	rotate_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	rotate(a);
	write(1, "ra\n", 3);
	return ;
}

void	rotate_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(b);
	write(1, "rb\n", 3);
	return ;
}

void	rotate_ab(t_stack **a, t_stack **b)
{
	if (!a || !*a || !(*a)->next)
		return ;
	if (!b || !*b || !(*b)->next)
		return ;
	rotate(a);
	rotate(b);
	write(1, "rr\n", 3);
	return ;
}
