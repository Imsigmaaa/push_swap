/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:26:33 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 16:52:44 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;

	if (!*stack_a)
		return ;
	node_a = *stack_a;
	*stack_a = (*stack_a)->next;
	stackadd_front(stack_b, node_a);
	write(1, "pb\n", 3);
	//print_stacks(*stack_a, *stack_b, "After pb");
	return ;
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_b;

	if (!*stack_b)
		return ;
	node_b = *stack_b;
	*stack_b = (*stack_b)->next;
	stackadd_front(stack_a, node_b);
	write(1, "pa\n", 3);
	//print_stacks(*stack_a, *stack_b, "After pa");
	return ;
}
