/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 13:48:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/04 21:20:41 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	recount_post(t_stack **stack)
{
	t_stack *new;
	int		i;

	new = *stack;
	i = 0;
	while (new)
	{
		new->post = i;
		i ++;
		new = new->next;
	}
	
	return (i);
}

int count_len(t_stack **stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i ++;
	}
	
}

int	count_cost(t_stack *temp_a, t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*target_b;
	int 	cost;
	int		len_a;
	int		len_b;

	target_b = find_target_b(temp_a, stack_b);
	len_a = count_len(stack_a);
	len_b = count_len(stack_b);
	if(temp_a->post <= len_a / 2 && target_b->post <= len_b / 2)
		cost = temp_a->post + target_b->post;
	else if (temp_a->post <= len_a / 2 && target_b->post > len_b / 2)
		cost = temp_a->post + len_b - target_b->post;
	else if (temp_a->post > len_a / 2 && target_b->post > len_b / 2)
		cost = len_a - temp_a->post + len_b - target_b->post;
	else
		cost = len_a - temp_a->post + target_b->post;
	
	return (cost);
}

t_stack	*find_lesscost_node_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp_a;
	t_stack	*lesscost_node_a;
	int 	cost_a1;
	int 	cost_a2;

	temp_a = *stack_a;
	while (temp_a->next)
	{
		cost_a1 = count_cost(temp_a, stack_a, stack_b);
		cost_a2 = count_cost(temp_a->next,stack_a, stack_b);
		if(cost_a1 <= cost_a2)
			lesscost_node_a = temp_a;
		else
			lesscost_node_a = temp_a->next;
		temp_a = temp_a->next;
	}
	return (lesscost_node_a);	
}
void compare_rr_rrr(t_stack **stack_b, t_stack *lesscost_node_a, int post_a, int post_b)
{
	
	t_stack	*target_b;
	int		post_a;
	int		post_b;

	target_b = find_target_b(lesscost_node_a, stack_b);
	post_a = lesscost_node_a->post;
	post_b = target_b->post;
	
	if(post_a <= len_a / 2 && post_b <= len_b / 2)
		是 rr
	else if (post_a <= len_a / 2 && post_b > len_b / 2)
		ra rrb
	else if (post_a > len_a / 2 && post_b > len_b / 2)
		是 rrr
	else
		rra rb
}
void execute_fonction(t_stack **stack_a, t_stack **stack_b)
{
	int 	len_a;
	int 	len_b;
	int 	cost_a;
	int 	cost_b;
	t_stack	*lesscost_node_a;

	len_a = recount_post(stack_a);
	len_b == recount_post(stack_b);
	lesscost_node_a = find_lesscost_node_a(stack_a, stack_b, len_a, len_b);
	cost_a = lesscost_node_a->post;
	cost_b = target_b = find_target_b(lesscost_node_a, stack_b);
}

/*void	find_best(t_stack **stack_a, t_stack **stack_b)
{
	int i;
	int cost;
	t_stack	*temp;
	
	i = 0;
	if(!*stack_b)
	{
		i = push_b(stack_a,stack_b);
		i += push_b(stack_a, stack_b); 
	}
}*/

	
