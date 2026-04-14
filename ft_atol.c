/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:49:34 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/06 16:50:07 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *nptr)
{
	long	i;
	long	result;
	long	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (nptr[i] == 32 || (9 <= nptr[i] && nptr[i] <= 13))
		i ++;
	if (nptr[i] == '+' || nptr[i] == '-')
		if (nptr[i++] == '-')
			sign = -1;
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i ++;
	}
	return (result * sign);
}
