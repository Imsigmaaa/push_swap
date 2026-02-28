/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacklast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:04:07 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/28 00:34:19 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stacklast(t_stack *head)
{
    t_stack *end;
    
    end = head;
	if (!end)
		return (NULL);
    while (end->next)
        end = end->next;
    return (end);
}