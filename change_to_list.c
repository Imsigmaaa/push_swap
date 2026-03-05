/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:22:02 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 19:45:35 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] || s2[i]))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i ++;
	}
	return (0);
}

static void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*temp;

	temp = *lst;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	temp = *lst;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
}

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
	int		a;

	i = 0;
	int len = calcul_len(arr);
	node = NULL;
	head = NULL;
	while (arr[i])
	{
		index = 0;
		a = ft_atoi(arr[i]);
		while (index < len && a != str[index])
			index ++;
		node = stacknew(ft_atoi(arr[i]), index);
		if (!node)
			return (free(head), NULL);
		ft_stackadd_back(&head, node);
		i ++;
	}
	return (head);
}
