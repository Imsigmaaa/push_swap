/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:48:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/09 05:37:26 by xingchen         ###   ########.fr       */
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
	else
		cost = temp->cost_a + temp->cost_b;
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

int	count_cost_b(t_stack *temp, t_stack **stack_a, t_stack **stack_b)
{
	int		cost;
	int		len_a;
	int		len_b;

	len_a = count_len(stack_a);
	len_b = count_len(stack_b);

	if ((temp->post > len_b/2 && temp->target_pos > len_a/2)
    	|| (temp->post <= len_b/2 && temp->target_pos <= len_a/2))
    {
		if(temp->cost_a >= temp->cost_b)
			cost = temp->cost_a;
		else
			cost = temp->cost_b;
	}
	else
		cost = temp->cost_a + temp->cost_b;
	return (cost);
}

t_stack	*find_best_node_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_b1;
	t_stack	*temp_b2;
	t_stack	*node;
	int		cost_b1;
	int		cost_b2;

	temp_b1 = *stack_b;
	cost_b1 = count_cost_b(temp_b1, stack_a, stack_b);
	node = temp_b1;
	if (!temp_b1->next)
		return (node);
	temp_b2 = (*stack_b)->next;
	while (temp_b2)
	{
		cost_b2 = count_cost_b(temp_b2, stack_a, stack_b);
		if (cost_b1 > cost_b2)
		{
			node = temp_b2;
			cost_b1 = cost_b2;
		}
		temp_b2 = temp_b2->next;
	}
	return (node);
}
