/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:58:31 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 02:43:27 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stackswap(stack_a);
	write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_stack **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stackswap(stack_b);
	write(1, "sb\n", 3);
	return ;
}

void	swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	if (*stack_a && (*stack_a)->next)
		swap_a(stack_a);
	if (*stack_b && (*stack_b)->next)
		swap_b(stack_b);
	write(1, "ss\n", 3);
	return ;
}
