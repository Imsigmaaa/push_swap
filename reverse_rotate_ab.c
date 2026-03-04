/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 16:37:39 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/03 12:34:32 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	reverse_rotate_a(t_stack **stack_a)
{
	t_stack	*node_a;
	t_stack	*end;

	end = *stack_a;
	while (end->next->next)
		end = end->next;
	node_a = end;
	end->next = NULL;
	node_a = node_a->next;
	stackadd_front(stack_a, node_a);
	return (write(1, "rra\n", 4) - 3);
}

int	reverse_rotate_b(t_stack **stack_b)
{
	t_stack	*node_b;
	t_stack	*end;

	end = *stack_b;
	while (end->next->next)
		end = end->next;
	node_b = end;
	end->next = NULL;
	node_b = node_b->next;
	stackadd_front(stack_b, node_b);
	return (write(1, "rra\n", 4) - 3);
}

int	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node_a;
	t_stack	*node_b;
	t_stack	*end_a;
	t_stack	*end_b;

	end_a = *stack_a;
	end_b = *stack_b;
	while (end_a->next->next)
		end_a = end_a->next;
	node_a = end_a;
	node_a = node_a->next;
	end_a->next = NULL;
	stackadd_front(stack_a, node_a);
	while (end_b->next->next)
		end_b = end_b->next;
	node_b = end_b;
	node_b = node_b->next;
	end_b->next = NULL;
	stackadd_front(stack_b, node_b);
	return (write(1, "rrr\n", 4) - 3);
}
