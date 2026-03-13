/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:26:33 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:28:51 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **a, t_stack **b)
{
	t_stack	*node_a;

	if (!*a)
		return ;
	node_a = *a;
	*a = (*a)->next;
	stackadd_front(b, node_a);
	write(1, "pb\n", 3);
	return ;
}

void	push_a(t_stack **a, t_stack **b)
{
	t_stack	*node_b;

	if (!*b)
		return ;
	node_b = *b;
	*b = (*b)->next;
	stackadd_front(a, node_b);
	write(1, "pa\n", 3);
	return ;
}
