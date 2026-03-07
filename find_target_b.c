/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:56:36 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 05:57:49 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_best_target(int index, t_stack **big, t_stack **least, t_stack **bigltl)
{
	t_stack	*temp;

	temp = *big;
	while (temp)
	{
		if (temp->index > (*big)->index)
			*big = temp;
		if (temp->index < (*least)->index)
			*least = temp;
		if(temp->index < index)
		{
			if (!*bigltl || temp->index > (*bigltl)->index)
				*bigltl = temp;
		}
		temp = temp->next;
	}
}

t_stack	*find_target_b(int index, t_stack **stack_b)
{
	t_stack	*big;
	t_stack	*bigltl;
	t_stack	*least;
	t_stack	*temp;

	bigltl = NULL;
	least = *stack_b;
	big = *stack_b;
	temp = *stack_b;
	while (temp)
	{
		if (temp->index > big->index)
			big = temp;
		if (temp->index < least->index)
			least = temp;
		if(temp->index < index &&
			(!bigltl || temp->index > bigltl->index))
				bigltl = temp;
		temp = temp->next;
	}
	if (index > big->index || index < least->index)
		return (big);
	return (ltlbig);
}
