/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_to_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 13:22:02 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/26 21:54:44 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

void	ft_stackadd_back(t_stack **lst, t_stack *new)
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

t_stack	*ft_stacknew(int val)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = val;
	new->next = NULL;
	return (new);
}

t_stack *change_to_list(char **arr)
{
	t_stack *node = NULL;
	t_stack *head;
	//t_stack *temp;
	
	int i;
	i = 0;
	head = NULL;
	while (arr[i])
	{
		node = ft_stacknew(ft_atoi(arr[i]));
		if (!node)
		{
			free(head);
			return NULL;
		}
		ft_stackadd_back(&head,node);
		i ++;
	}
	t_stack *temp = head;
	while (temp)
	{
		printf("%d\n", temp->value);
		temp = temp->next;
	}
	
	return(head);
}