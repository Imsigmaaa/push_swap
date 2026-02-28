/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 10:58:31 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/28 11:27:51 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_a(t_stack *stack_a)
{

	if(!stack_a || !(stack_a)->next)
		return (0);
	stackswap(stack_a);
	return (write(1,"sa\n",3) - 2);
}

int	swap_b(t_stack *stack_b)
{
	if(!stack_b || !(stack_b)->next)
		return (0);
	stackswap(stack_b);
	return (write(1,"sb\n",3) - 2);
}

int swap_ab(t_stack *stack_a,t_stack *stack_b)
{
	if(!stack_a && !stack_b)
		return (0);
	else if(!stack_a || !(stack_a)->next && stack_b && stack_b->next)
		return (swap_b(stack_b));
	else if (!stack_b || !(stack_b)->next && stack_a && stack_a->next)
		return (swap_b(stack_b));
	else
	{
		stackswap(stack_a);
		stackswap(stack_b);
		return (write(1,"ss\n",3) - 2);
	}

}