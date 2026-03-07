/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:37:39 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 02:42:29 by xingchen         ###   ########.fr       */
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

void	reverse_rotate_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	reverse_rotate_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		reverse_rotate_a(stack_a);
	if (*stack_b && (*stack_b)->next)
		reverse_rotate_b(stack_b);
	return ;
}
