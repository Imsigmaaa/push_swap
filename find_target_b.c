/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:56:36 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 18:14:52 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_biggest_value(t_stack **stack)
{
	t_stack	*big;
	t_stack	*temp;

	temp = *stack;
	big = *stack;
	while (temp)
	{
		if (temp->index > big->index)
			big = temp;
		temp = temp->next;
	}
	return (big);
}

t_stack	*find_least_value(t_stack **stack)
{
	t_stack	*least;
	t_stack	*temp;

	temp = *stack;
	least = *stack;
	while (temp)
	{
		if (temp->index < least->index)
			least = temp;
		temp = temp->next;
	}
	return (least);
}

t_stack	*find_littlebigger_value(int index, t_stack **stack)
{
	t_stack	*ltlbig;
	t_stack	*temp;

	temp = *stack;
	while (temp)
	{
		if (index == temp->index - 1)
		{
			ltlbig = temp;
			return (ltlbig);
		}
		temp = temp->next;
	}
	return (NULL);
}

t_stack	*find_target_b(int index, t_stack **stack_b)
{
	t_stack	*big;
	t_stack	*ltlbig;
	t_stack	*least;
	t_stack	*target_b;

	big = find_biggest_value(stack_b);
	least = find_least_value(stack_b);
	if (index > big->index || index < least->index)
		target_b = big;
	else
	{
		ltlbig = find_littlebigger_value(index, stack_b);
		target_b = ltlbig;
	}
	//target_b->next = NULL;
	return (target_b);
}
