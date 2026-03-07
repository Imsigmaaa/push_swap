/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:29:16 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 02:42:39 by xingchen         ###   ########.fr       */
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
void	rotate_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
		return ;
}

void	rotate_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
		return ;
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	if(*stack_a && (*stack_a)->next)
		rotate_a(stack_a);
	if (*stack_a && (*stack_a)->next)
		rotate_b(stack_b);
	write(1, "rr\n", 3);
	return ;
}
