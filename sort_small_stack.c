/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 21:15:27 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:30:55 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_a0_less_a1(t_stack **a)
{
	if ((*a)->next->index < (*a)->next->next->index)
		return ;
	else if ((*a)->index < (*a)->next->next->index)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else
		reverse_rotate_a(a);
}

void	handle_a0_greater_a1(t_stack **a)
{
	if ((*a)->index < (*a)->next->next->index)
		swap_a(a);
	else if ((*a)->next->index < (*a)->next->next->index)
		rotate_a(a);
	else
	{
		rotate_a(a);
		swap_a(a);
	}
}

void	small_sort(t_stack **a, t_stack **b)
{
	int	i;
	int	size_a;

	i = stack_size(a);
	if (i == 2)
	{
		swap_a(a);
		return ;
	}
	while (i-- > 3)
		push_b(a, b);
	size_a = stack_size(a);
	if (size_a == 3)
	{
		if ((*a)->index < (*a)->next->index)
			handle_a0_less_a1(a);
		else
			handle_a0_greater_a1(a);
	}
}
