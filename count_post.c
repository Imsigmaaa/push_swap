/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_post.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:58:22 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 13:00:44 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_post(t_stack **stack, t_stack *target)
{
	int	post;
	int	len;

	len = count_len(stack);
	post = len - target->post;
	return (post);
}
