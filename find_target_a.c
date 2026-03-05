/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_target_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:48:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 21:56:00 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_lesscost(int post_a, int post_b)
{
	int cost;

	if(post_a == 0 && post_b == 0)
		cost = 0;
	else if ( post_a == 0 || post_b == 0)
		cost = post_a + post_b;
	else if(post_a >= post_b)
		cost = post_a;
	else
		cost = post_b;
	return (cost);
	
}
int	count_cost(t_stack *temp_a, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target_b;
	int		cost;
	int		len_a;
	int		len_b;
	
	target_b = find_target_b(temp_a->index, stack_b);
	len_a = count_len(stack_a);
	len_b = count_len(stack_b);
	if (temp_a->post <= len_a / 2 && target_b->post <= len_b / 2)
		cost = count_lesscost(temp_a->post, target_b->post);
	else if (temp_a->post <= len_a / 2 && target_b->post > len_b / 2)
		cost = temp_a->post + len_b - target_b->post;
	else if (temp_a->post > len_a / 2 && target_b->post > len_b / 2)
		cost = count_lesscost(len_a - temp_a->post, len_b - target_b->post);
	else
		cost = len_a - temp_a->post + target_b->post;
	return (cost);
}

t_stack	*find_target_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a1;
	t_stack	*temp_a2;
	t_stack	*target_a;
	int		cost_a1;
	int		cost_a2;

	temp_a1 = *stack_a;
	cost_a1 = count_cost(temp_a1, stack_a, stack_b);
	target_a = temp_a1;
	if (!temp_a1->next)
		return (target_a);
	temp_a2 = (*stack_a)->next;
	while (temp_a2)
	{
		ft_print_stack(temp_a2);
		cost_a2 = count_cost(temp_a2, stack_a, stack_b);
		if (cost_a1 > cost_a2)
		{
			target_a = temp_a2;
			cost_a1 = cost_a2;
		}
		temp_a2 = temp_a2->next;
		/*printf("--------find---------------------\n");
		ft_print_stack(target_a);*/
	}
	printf("--------find---------------------\n");
	//ft_print_stack(target_a);
	return (target_a);
}
