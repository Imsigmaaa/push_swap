/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:58:31 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:26:52 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackswap(t_stack **stack)
{
	int	swap_value;
	int	swap_index;

	if (!*stack || !(*stack)->next)
		return ;
	swap_value = (*stack)->value;
	swap_index = (*stack)->index;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value = swap_value;
	(*stack)->next->index = swap_index;
}

void	swap_a(t_stack **a)
{
	if (!a || !*a || !(*a)->next)
		return ;
	stackswap(a);
	write(1, "sa\n", 3);
	return ;
}

void	swap_b(t_stack **b)
{
	if (!b || !*b || !(*b)->next)
		return ;
	stackswap(b);
	write(1, "sb\n", 3);
	return ;
}

void	swap_ab(t_stack **a, t_stack **b)
{
	if (*a && (*a)->next)
		swap_a(a);
	if (*b && (*b)->next)
		swap_b(b);
	write(1, "ss\n", 3);
	return ;
}
