/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:18:04 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/13 14:58:37 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		if (n == -2147483648)
			return (ft_putstr("-2147483648"));
		else
		{
			count += ft_putchar('-');
			count += ft_putnbr(-n);
		}
	}
	if (0 <= n && n <= 9)
		count += ft_putchar(n + '0');
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
