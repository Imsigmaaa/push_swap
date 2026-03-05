/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_ab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 11:29:16 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 15:04:12 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stackadd_back(t_stack **stack)
{
	t_stack	*node;
	t_stack	*temp;

	if (*stack == NULL)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	node->next = NULL;
	temp = *stack;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}

int	rotate_a(t_stack **stack_a)
{
	if (!*stack_a || !(*stack_a)->next)
		return (0);
	else if (!(*stack_a)->next->next)
	{
		stackswap(stack_a);
		return (write(1, "ra\n", 3) - 2);
	}
	else
	{
		ft_stackadd_back(stack_a);
		return (write(1, "ra\n", 3) - 2);
	}
}

int	rotate_b(t_stack **stack_b)
{
	if (!*stack_b || !(*stack_b)->next)
		return (0);
	else if (!(*stack_b)->next->next)
	{
		stackswap(stack_b);
		return (write(1, "rb\n", 3) - 2);
	}
	else
	{
		ft_stackadd_back(stack_b);
		return (write(1, "rb\n", 3) - 2);
	}
}

int	rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_stackadd_back(stack_a);
	ft_stackadd_back(stack_b);
	return (write(1, "rr\n", 3) - 2);
}
