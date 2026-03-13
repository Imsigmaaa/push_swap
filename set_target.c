/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:56:36 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:14:39 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_target(int index, t_stack **stack)
{
	t_stack	*big;
	t_stack	*bigltl;
	t_stack	*least;
	t_stack	*temp;

	bigltl = NULL;
	least = *stack;
	big = *stack;
	temp = *stack;
	while (temp)
	{
		if (temp->index > big->index)
			big = temp;
		if (temp->index < least->index)
			least = temp;
		if (temp->index > index
			&& (!bigltl || temp->index < bigltl->index))
			bigltl = temp;
		temp = temp->next;
	}
	if (index > big->index || index < least->index)
		return (least);
	return (bigltl);
}

void	set_target(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	t_stack	*target;

	temp = *b;
	while (temp)
	{
		target = find_target(temp->index, a);
		temp->target_pos = target->post;
		temp = temp->next;
	}
}
