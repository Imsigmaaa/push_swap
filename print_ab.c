/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:55:20 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 17:32:58 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ab_rrr(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b)
{
	int	i;
	int	times;

	i = 0;
	if (count_len(st_a) - tag_a->post < count_len(st_b) - tag_b->post)
	{
		times = count_post(st_a, tag_a) + i;
		while (count_post(st_a, tag_a) != 0 && i < times)
			i += reverse_rotate_ab(st_a, st_b);
		times = count_post(st_b, tag_b) - count_post(st_a, tag_a) + i;
		while (i < times)
			i += reverse_rotate_b(st_b);
	}
	else
	{
		times = count_len(st_b) - tag_b->post + i;
		while (tag_b->post != 0 && i < times)
			i += reverse_rotate_ab(st_a, st_b);
		times = count_post(st_a, tag_a) - count_post(st_b, tag_b) + i;
		while (i < times)
			i += reverse_rotate_a(st_a);
	}
	/*printf("---------ab_and_rrr----------\n");
	print_stack(st_a);
	printf("---------ab_and_rrr----------\n");
	print_stack(st_b);
	printf("---------ab_and_rrr----------\n");*/
	return (i);
}

int	ab_rr(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b)
{
	int	i;
	int	times;

	i = 0;
	if (tag_a->post < tag_b->post)
	{
		times = tag_a->post + i;
		while (tag_a->post != 0 && i < times)
			i += rotate_ab(st_a, st_b);
		times = tag_b->post - tag_a->post + i;
		while (i < times)
			i += rotate_b(st_b);
	}
	else
	{
		times = tag_b->post + i;
		while (tag_b->post != 0 && i < times)
			i += rotate_ab(st_a, st_b);
		times = tag_a->post - tag_b->post + i;
		while (i < times)
			i += rotate_a(st_a);
	}
	/*printf("---------ab_and_rr----------\n");//没问题
	print_stack(st_a);
	printf("---------ab_and_rr----------\n");
	print_stack(st_b);
	printf("---------ab_and_rr----------\n");*/
	return (i);
}

int	rra_and_rb(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b)
{
	int	post_a;
	int	post_b;
	int	i;
	int	times;

	post_a = tag_a->post;
	post_b = tag_b->post;
	i = 0;
	/*printf("-----3----rra_and_rb----------\n");
	print_stack(st_a);
	printf("----3-----rra_and_rb----------\n");
	print_stack(st_b);
	printf("-------3--rra_and_rb----------\n");*/
	times = i + count_len(st_a) - post_a;
	while (i < times)
		i += reverse_rotate_a(st_a);
	times = i + post_b;
	while (i < times)
		i += rotate_b(st_b);
	
	return (i);
}

int	rrb_and_ra(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b)
{
	int	post_a;
	int	post_b;
	int	i;
	int	times;

	i = 0;
	post_a = tag_a->post;
	post_b = tag_b->post;
	/*printf("---------rrb_and_ra----------\n");
	print_stack(st_a);
	printf("---------rrb_and_ra----------\n");
	print_stack(st_b);
	printf("---------rrb_and_ra----------\n");*/
	times = i + count_len(st_b) - post_b;
	while (i < times)
		i += reverse_rotate_b(st_b);
	//print_stack(st_b);
	times = i + post_a;
	while (i < times)
		i += rotate_a(st_a);
	/*printf("---------rrb_and_ra----------\n");
	print_stack(st_a);
	printf("---------rrb_and_ra----------\n");
	print_stack(st_b);
	printf("---------rrb_and_ra----------\n");*/
	return (i);
}

int	print_ab(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b)
{
	int	len_a;
	int	len_b;
	int	post_a;
	int	post_b;
	int	i;

	post_a = tag_a->post;
	post_b = tag_b->post;
	len_a = count_len(st_a);
	len_b = count_len(st_b);
	i = 0;
	if (post_a > len_a / 2 && post_b > len_b / 2)
		i = ab_rrr(st_a, st_b, tag_a, tag_b);

		
	else if (post_a <= len_a / 2 && post_b <= len_b / 2)
		i = ab_rr(st_a, st_b, tag_a, tag_b);
		
	else if (post_a > len_a / 2 && post_b <= len_b / 2)
		i = rra_and_rb(st_a, st_b, tag_a, tag_b);
		
		
	else
		i = rrb_and_ra(st_a, st_b, tag_a, tag_b);
	return (i);
}
