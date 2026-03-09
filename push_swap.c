/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/04 21:04:46 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/09 05:51:47 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort_stack(t_stack **stack)
{
	t_stack *temp;
	int i;
	int len;

	i = 0;
	len = count_len(stack);
	temp = *stack;
	while (temp && i < len)
	{
		if(temp->index != i)
			return (0);
		i ++;
		temp = temp->next;
	}
	return (1);
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
void	recount_cost(t_stack **st_a, t_stack **st_b)
{
	int	len_a;
	int	len_b;
	t_stack	*temp;

	temp = *st_a;
	len_a = count_len(st_a);
	len_b = count_len(st_b);
	while (temp)
	{
		if(temp->post <= len_a/2)
			temp->cost_a = temp->post;
		else
			temp->cost_a =len_a - temp->post;
		if(temp->target_pos <= len_b/2)
			temp->cost_b = temp->target_pos;
		else
			temp->cost_b =len_b - temp->target_pos;
		//fprintf(stderr, "index=%d post_a=%d cost_a=%d target_pos=%d cost_b=%d\n",
       //     temp->index, temp->post, temp->cost_a, temp->target_pos, temp->cost_b);
		temp = temp->next;
	}
}
void	recount_cost_b(t_stack **st_a, t_stack **st_b)
{
	int	len_a;
	int	len_b;
	t_stack	*temp;

	temp = *st_b;
	len_a = count_len(st_a);
	len_b = count_len(st_b);
	while (temp)
	{
		if(temp->post <= len_b/2)
			temp->cost_b = temp->post;
		else
			temp->cost_b =len_b - temp->post;
		if(temp->target_pos <= len_a/2)
			temp->cost_a = temp->target_pos;
		else
			temp->cost_a =len_a - temp->target_pos;
		/*fprintf(stderr, "index=%d post_a=%d cost_a=%d target_pos=%d cost_b=%d\n",
        	temp->index, temp->post, temp->cost_a, temp->target_pos, temp->cost_b);*/
		temp = temp->next;
	}
}
void	sort_b(t_stack **st_b)
{
	int		len;
	t_stack	*big;
	t_stack	*temp;
	int time;

	len = count_len(st_b);
	recount_post(st_b);
	big = *st_b;
	
	temp = *st_b;
	//fprintf(stderr, "before sort_b: index=%dpost=%d len=%d\n", big->index,big->post, len);
	while (temp)
	{
		
		if(temp->index > big->index)
			big = temp;
		temp = temp->next;
	}
	//fprintf(stderr, "After sort_b: index=%d post=%d len=%d\n", big->index,big->post,len);
	if (big->post <= len / 2)
	{
		while (big->post > 0)
		{
			rotate_b(st_b);
			big->post --;
		}
	}
	else
	{
		 time= len - big->post;
		while ( time-- > 0)
		{
			reverse_rotate_b(st_b);
		}
	}
	//fprintf(stderr, "After sort_b: index=%d post=%d time=%d\n", big->index,big->post,time);
}
void	sort_a(t_stack **st_a)
{
	int		len;
	t_stack	*least;
	t_stack	*temp;
	int time;

	len = count_len(st_a);
	recount_post(st_a);
	least = *st_a;
	
	temp = *st_a;
	//fprintf(stderr, "before sort_b: index=%dpost=%d len=%d\n", big->index,big->post, len);
	while (temp)
	{
		if(temp->index < least->index)
			least = temp;
		temp = temp->next;
	}
	/*fprintf(stderr, "After sort_b: index=%d post=%d len=%d\n", big->index,big->post,len);*/
	if (least->post <= len / 2)
	{
		while (least->post > 0)
		{
			rotate_a(st_a);
			least->post --;
		}
	}
	else
	{
		 time= len - least->post;
		while ( time-- > 0)
		{
			reverse_rotate_a(st_a);
		}
	}
	//fprintf(stderr, "After sort_b: index=%d post=%d time=%d\n", big->index,big->post,time);
}
void	recount_target_pos_a(t_stack **st_a, t_stack **st_b)
{
	t_stack	*temp;
	t_stack	*target_b;
	
	temp = *st_a;
	while (temp)
	{
		target_b = find_target_b(temp->index, st_b);
		temp->target_pos = target_b->post;
		temp = temp->next;
	}
	
}
void	recount_target_pos_b(t_stack **st_a, t_stack **st_b)
{
	t_stack	*temp;
	t_stack	*target_a;
	
	temp = *st_b;
	while (temp)
	{
		target_a = find_target_a(temp->index, st_a);
		temp->target_pos = target_a->post;
		temp = temp->next;
	}
	
}

/*void	push_swap_a(t_stack **st_a, t_stack **st_b)
{
	t_stack	*node;

	while (*st_b)
	{
		recount_post(st_a);
		recount_post(st_b);
		recount_target_pos_b(st_a, st_b);
		recount_cost(st_a, st_b);
		node = find_best_node(st_b, st_a);
		print_ab(st_a, st_b, node);
		if(*st_b)
			push_a(st_a, st_b);
	}
	sort_a(st_a);
}*/

void	push_swapformin(t_stack **st_a, t_stack **st_b)
{
	int	len_a;

	len_a = count_len(st_a);
	if(!*st_b && len_a == 1)
		return	;
	if (!*st_b && len_a == 2)
	{
		if ((*st_a)->index > (*st_a)->next->index)
			swap_a(st_a);
		else
			return;
	}
	if (!*st_b && len_a == 3)
	{
		if ((*st_a)->index < (*st_a)->next->index)
		{
			if((*st_a)->next->index < (*st_a)->next->next->index)
				return	;
			else if ((*st_a)->index < (*st_a)->next->next->index)
			{
				reverse_rotate_a(st_a);
				swap_a(st_a);
			}
			else
				reverse_rotate_a(st_a);
			
		}
		else
		{
			if((*st_a)->index < (*st_a)->next->next->index)
				swap_a(st_a);
			else if ((*st_a)->next->index < (*st_a)->next->next->index)
				rotate_a(st_a);
			else
			{
				rotate_a(st_a);
				swap_a(st_a);
			}
		}
	}	
}
void	recount_form_b_to_a(t_stack **st_a, t_stack **st_b)
{
	t_stack *node;

	while (*st_b)
	{
		recount_post(st_a);
		recount_post(st_b);
		recount_target_pos_b(st_a, st_b);
		recount_cost_b(st_a, st_b);
		node = find_best_node_b(st_a, st_b);
		push_b2a(st_a, st_b, node);
		push_a(st_a,st_b);
	}
}

void _5_number_in_stack_a(t_stack **st_a,t_stack **st_b)
{
	if ((*st_a)->index < (*st_a)->next->index)
	{
		if((*st_a)->next->index < (*st_a)->next->next->index)
			recount_form_b_to_a(st_a, st_b);
		else if ((*st_a)->index < (*st_a)->next->next->index)
		{
			reverse_rotate_a(st_a);
			swap_a(st_a);
			recount_form_b_to_a(st_a,st_b);
		}
		else
		{
			reverse_rotate_a(st_a);
			recount_form_b_to_a(st_a,st_b);
		}
	}
	else
	{
		if((*st_a)->index < (*st_a)->next->next->index)
		{
			swap_a(st_a);
			recount_form_b_to_a(st_a,st_b);
		}
		else if ((*st_a)->next->index < (*st_a)->next->next->index)
		{
			rotate_a(st_a);
			recount_form_b_to_a(st_a,st_b);
		}
		else
		{
			rotate_a(st_a);
			swap_a(st_a);
			recount_form_b_to_a(st_a,st_b);
		}
	}
	sort_a(st_a);
}
	
void	push_swap(t_stack **st_a, t_stack **st_b)
{
	t_stack	*node;

	if(is_sort_stack(st_a))
		return ;
	push_b(st_a, st_b);
	push_b(st_a, st_b);
	if(count_len(st_a)==3)
	{
		_5_number_in_stack_a(st_a,st_b);
		return ;
	}
	while (*st_a)
	{
		recount_post(st_a);
		recount_post(st_b);
		recount_target_pos_a(st_a, st_b);
		recount_cost(st_a, st_b);
		node = find_best_node(st_a, st_b);
		print_ab(st_a, st_b, node);
		if(!(*st_a))
			break ;
		push_b(st_a, st_b);	
	}
	sort_b(st_b);
	while (*st_b)
		push_a(st_a, st_b);	
}

/*sort_b(st_b);
	while (*st_b)
		push_a(st_a, st_b);*/