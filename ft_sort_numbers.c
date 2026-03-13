/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_numbers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 20:39:39 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:12:05 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	ft_swap(int *a, int *b)
{
	int	swap;

	swap = *a;
	*a = *b;
	*b = swap;
}

static	int	arr_len(char **arr)
{
	int	len;

	len = 0;
	while (arr[len])
		len ++;
	return (len);
}

static	void	sort_in_array(int *str, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		if ((str[i] > str[i + 1]))
		{
			ft_swap(&str[i], &str[i + 1]);
			i = 0;
		}
		else
			i ++;
	}
}

int	*ft_sort_numbers(char **arr)
{
	int	i;
	int	len;
	int	*str;

	len = arr_len(arr);
	str = malloc(sizeof(int) * len);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = ft_atoi(arr[i]);
		i ++;
	}
	sort_in_array(str, len);
	return (str);
}
