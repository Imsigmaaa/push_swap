/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stackswap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:13:41 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/28 11:17:21 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stackswap(t_stack *stack)
{
	int swap;

	if(!stack || !stack->next)
		return ;
	swap = stack->value;
	stack->value = stack->next->value;
	stack->next->value = swap;
}