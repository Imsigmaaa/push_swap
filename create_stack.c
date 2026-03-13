/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:22:02 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 15:56:10 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	t_stack	*stack_new(int val, int index)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = val;
	new->index = index;
	new->post = 0;
	new->next = NULL;
	return (new);
}

static	int	arr_len(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i ++;
	return (i);
}

t_stack	*create_stack(char **arr, int *str)
{
	t_stack	*new;
	t_stack	*head;
	int		index;
	int		i;
	int		len;

	i = 0;
	head = NULL;
	len = arr_len(arr);
	while (arr[i])
	{
		index = 0;
		while (index < len && ft_atoi(arr[i]) != str[index])
			index ++;
		new = stack_new(ft_atoi(arr[i]), index);
		if (!new)
			return (stack_clear(&head), NULL);
		stackadd_back(&head, new);
		i ++;
	}
	return (ft_free_arr(arr), free(str), head);
}
