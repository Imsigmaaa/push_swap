/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:48:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/06 23:32:25 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_cost(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	int		len_a;
	int		len_b;

	len_a = count_len(stack_a);
	len_b = count_len(stack_b);

	if ((temp->post > len_a/2 && temp->target_pos > len_b/2)
    	|| (temp->post <= len_a/2 && temp->target_pos <= len_b/2))
    {
		if(temp->cost_a >= temp->cost_b)
			cost = temp->cost_a;
		else
			cost = temp->cost_b;
	}
	else if (temp->post <= len_a / 2 && temp->target_pos > len_b / 2)
		cost = temp->post + len_b - temp->target_pos;
	else
		cost = len_a - temp->post + temp->target_pos;
	return (cost);
}

t_stack	*find_best_node(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a1;
	t_stack	*temp_a2;
	t_stack	*node;
	int		cost_a1;
	int		cost_a2;

	temp_a1 = *stack_a;
	cost_a1 = count_cost(temp_a1, stack_a, stack_b);
	node = temp_a1;
	if (!temp_a1->next)
		return (node);
	temp_a2 = (*stack_a)->next;
	while (temp_a2)
	{
		cost_a2 = count_cost(temp_a2, stack_a, stack_b);
		if (cost_a1 > cost_a2)
		{
			node = temp_a2;
			cost_a1 = cost_a2;
		}
		temp_a2 = temp_a2->next;
	}
	return (node);
}
