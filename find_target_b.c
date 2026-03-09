/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 18:56:36 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 15:42:27 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		//fprintf(stderr, "find_target_b: index=%d -> big index=%d post=%d\n", 
           // index, big->index, big->post);
		return (big);
	}
	// fprintf(stderr, "find_target_b: index=%d -> bigltl index=%d post=%d\n", 
      //  index, bigltl->index, bigltl->post);
	return (bigltl);
}
t_stack	*find_target_a(int index, t_stack **stack_a)
{
	t_stack	*big;
	t_stack	*bigltl;
	t_stack	*least;
	t_stack	*temp;

	bigltl = NULL;
	least = *stack_a;
	big = *stack_a;
	temp = *stack_a;
	while (temp)
	{
		if (temp->index > big->index)
			big = temp;
		if (temp->index < least->index)
			least = temp;
		if(temp->index > index &&
			(!bigltl || temp->index < bigltl->index))
				bigltl = temp;
		temp = temp->next;
	}
	if (index > big->index || index < least->index)
		return (least);
	return (bigltl);
}
