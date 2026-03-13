/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:48:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 15:25:42 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int	calculate_cost(t_stack *temp, t_stack **a, t_stack **b)
{
	int		cost;
	int		len_a;
	int		len_b;

	len_a = stack_size(a);
	len_b = stack_size(b);
	if ((temp->post > len_b / 2 && temp->target_pos > len_a / 2)
		|| (temp->post <= len_b / 2 && temp->target_pos <= len_a / 2))
	{
		if (temp->cost_a >= temp->cost_b)
			cost = temp->cost_a;
		else
			cost = temp->cost_b;
	}
	else
		cost = temp->cost_a + temp->cost_b;
	return (cost);
}

t_stack	*find_best_node(t_stack **a, t_stack **b)
{
	t_stack	*temp_b1;
	t_stack	*temp_b2;
	t_stack	*node;
	int		cost_b1;
	int		cost_b2;

	temp_b1 = *b;
	cost_b1 = calculate_cost(temp_b1, a, b);
	node = temp_b1;
	if (!temp_b1->next)
		return (node);
	temp_b2 = (*b)->next;
	while (temp_b2)
	{
		cost_b2 = calculate_cost(temp_b2, a, b);
		if (cost_b1 > cost_b2)
		{
			node = temp_b2;
			cost_b1 = cost_b2;
		}
		temp_b2 = temp_b2->next;
	}
	return (node);
}
