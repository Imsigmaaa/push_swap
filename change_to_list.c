/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:22:02 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 01:39:22 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stacknew(int val, int index)
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

t_stack	*change_to_list(char **arr, int *str)
{
	t_stack	*node;
	t_stack	*head;
	int		index;
	int		i;
	int		len;

	i = 0;
	node = NULL;
	head = NULL;
	len = calcul_len(arr);
	while (arr[i])
	{
		index = 0;
		while (index < len && ft_atoi(arr[i]) != str[index])
			index ++;
		node = stacknew(ft_atoi(arr[i]), index);
		if (!node)
			return (ft_stackclear(&head), NULL);
		stackadd_back(&head, node);
		i ++;
	}
	return (ft_free_arr(arr), free(str), head);
}
