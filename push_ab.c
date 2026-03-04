/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:26:33 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/03 12:34:50 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;

	if (!*stack_a)
		return (0);
	node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	stackadd_front(stack_b, node_a);
	return (write(1, "pb\n", 3) - 2);
}

int	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_b;

	if (!*stack_b)
		return (0);
	node_b = *stack_b;
	*stack_b = (*stack_b)->next;
	stackadd_front(stack_a, node_b);
	return (write(1, "pa\n", 3) - 2);
}
