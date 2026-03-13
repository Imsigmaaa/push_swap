/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:28:20 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 15:29:02 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*find_min(t_stack **stack)
{
	t_stack	*min;
	t_stack	*temp;

	min = *stack;
	temp = *stack;
	while (temp)
	{
		if (min->index > temp->index)
			min = temp;
		temp = temp->next;
	}
	return (min);
}

void	sort_stack(t_stack **stack)
{
	int		len;
	int		i;
	t_stack	*min;

	len = stack_size(stack);
	set_position(stack);
	min = find_min(stack);
	if (min->post <= len / 2)
	{
		i = min->post;
		while (i-- > 0)
			rotate_a(stack);
	}
	else
	{
		i = len - min->post;
		while (i-- > 0)
			reverse_rotate_a(stack);
	}
}
