/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:04:23 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/10 01:22:24 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack **stack)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (temp)
	{
		i ++;
		temp = temp->next;
	}
	return (i);
}

void	stackadd_back(t_stack **stack, t_stack *new)
{
	t_stack	*temp;

	temp = *stack;
	if (*stack == NULL)
	{
		*stack = new;
		return ;
	}
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

void	stackadd_front(t_stack **stack, t_stack *node)
{
	node->next = *stack;
	*stack = node;
}

void	stack_clear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}
