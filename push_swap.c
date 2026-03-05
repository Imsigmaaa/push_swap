/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:04:46 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 19:00:42 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void print_stack(t_stack **stack)
{
	t_stack *temp;

	temp = *stack;
	if(!temp)
		printf("null\n");
	while (temp)
	{
		printf("value=%d,index=%d,post=%d\n",temp->value,temp->index,temp->post);
		temp = temp->next;
	}
}

void	recount_post(t_stack **stack)
{
	int		i;
	t_stack	*new;
	new = *stack;
	
	i = 0;
	while (new)
	{
		new->post = i;
		i ++;
		new = new->next;
	}
}
int sort_b(t_stack **st_b)
{
	int	i;
	int len;

	t_stack	*big;
	i = 0;
	big = find_biggest_value(st_b);
	len = count_len(st_b);
	recount_post(st_b);
	if(big->post <= len / 2)
	{
		while (i < big->post)
		i += rotate_b(st_b);
	}
	else
	{
		while (i < len - big->post)
			i += reverse_rotate_b(st_b);
	}
	return i;
}
int	push_swap(t_stack **st_a, t_stack **st_b)
{
	int		i;
	t_stack	*tag_a;
	t_stack	*tag_b;

	i = 0;
	i += push_b(st_a,st_b);
	i += push_b(st_a,st_b);
	while (*st_a)
	{
		recount_post(st_a);
		recount_post(st_b);
		printf("--------PUSH_SWAP每次重新计算位置stacka---------------------\n");
		print_stack(st_a);
		printf("--------PUSH_SWAP每次重新计算位置stackb--------------------\n");
		print_stack(st_b);
		tag_a = find_target_a(st_a, st_b);
		tag_b = find_target_b(tag_a->index, st_b);
		printf("--------PUSH_SWAP每次重新计算位置targeta---------------------\n");
		ft_print_stack(tag_a);
		printf("--------PUSH_SWAP每次重新计算位置targetb---------------------\n");
		ft_print_stack(tag_b);
		printf("--------PUSH_SWAPendddddddddddddd---------------------\n");
		if (tag_a->post == 0 && tag_b->post == 0)
			i += push_b(st_a, st_b);
		else
			i += print_ab(st_a, st_b, tag_a, tag_b);
		i += push_b(st_a, st_b);
	}
	//i += sort_b(st_b);
	return (i);
}

