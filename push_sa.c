/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_sa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 22:26:33 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/26 23:49:39 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *creat_end_node(t_stack *head)
{
    t_stack *end;
    
    end = head;
    while (end->next)
        end = end->next;
    return (end);
}

int push_sa(t_stack **stack_a,t_stack **stack_b)
{
    t_stack *temp_a;
    temp_a = *stack_a;
    *stack_a = (*stack_a)->next;
    if (!*stack_b)
    {
        *stack_b = temp_a;
        temp_a->next = NULL;
    }
    else
    {    
        temp_a->next = (*stack_b)->next;
        *stack_b = temp_a;
    }
    return(write(1,"sa\n",3)-2);    
    
}