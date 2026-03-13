/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 23:14:48 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:30:06 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_cost(t_stack **a, t_stack **b)
{
	int		len_a;
	int		len_b;
	t_stack	*temp;

	temp = *b;
	len_a = stack_size(a);
	len_b = stack_size(b);
	while (temp)
	{
		if (temp->post <= len_b / 2)
			temp->cost_b = temp->post;
		else
			temp->cost_b = len_b - temp->post;
		if (temp->target_pos <= len_a / 2)
			temp->cost_a = temp->target_pos;
		else
			temp->cost_a = len_a - temp->target_pos;
		temp = temp->next;
	}
}
