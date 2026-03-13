/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_position.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 22:18:43 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/10 01:20:03 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack **stack)
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
