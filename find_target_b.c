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
	t_stack	*ltlbig;
	t_stack	*least;
	t_stack	*target_b;

	big = *stack_b;
	least = *stack_b;
	ltlbig = NULL;
	find_best_target(index,&big,&least,&ltlbig);
	if (index > big->index || index < least->index)
		target_b = big;
	else
		target_b = ltlbig;
	return (target_b);
}
