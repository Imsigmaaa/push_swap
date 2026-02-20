/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putposition.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 19:35:46 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/13 15:05:03 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_hex(unsigned long n)
{
	char	*hex;
	int		count;

	hex = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count += print_hex(n / 16);
	count += ft_putchar(hex[n % 16]);
	return (count);
}

int	ft_putposition(void *position)
{
	unsigned long	n;
	int				count;

	n = (unsigned long)position;
	count = 0;
	if (!position)
		return (ft_putstr("(nil)"));
	count += ft_putstr("0x");
	count += print_hex(n);
	return (count);
}
