/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:07:34 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/13 14:59:15 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int n)
{
	int	count;

	count = 0;
	if (n <= 9)
		count += ft_putchar(n + '0');
	if (n > 9)
	{
		count += ft_putunbr(n / 10);
		count += ft_putchar(n % 10 + '0');
	}
	return (count);
}
