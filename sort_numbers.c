/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:39:39 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/03 15:09:24 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

int	calcul_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len ++;
	return (len);
}

int	*sort_numbers(char **arr, int *str)
{
	int		i;
	int		len;

	len = calcul_len(arr);
	str = malloc(sizeof(int) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (arr[i])
	{
		str[i] = ft_atoi(arr[i]);
		i ++;
	}
	i = 0;
	while (i < len)
	{
		if (i + 1 < len && (str[i] > str[i + 1]))
		{
			ft_swap(&str[i], &str[i + 1]);
			i = 0;
		}
		else
			i ++;
	}
	return (str);
}
