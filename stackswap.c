/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:13:41 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/04 14:51:08 by xingchen         ###   ########.fr       */
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
	swap_index = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->index = (*stack)->next->index;
	(*stack)->next->value= swap_value;
	(*stack)->next->index = swap_index;
}
