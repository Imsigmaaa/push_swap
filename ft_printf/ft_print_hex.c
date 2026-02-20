/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 13:30:26 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/13 15:17:57 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int n, char c)
{
	char	*hex;
	int		count;

	count = 0;
	if (c == 'X')
		hex = "0123456789ABCDEF";
	if (c == 'x')
		hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putchar('0'));
	if (n >= 16)
		count += ft_print_hex(n / 16, c);
	count += ft_putchar(hex[n % 16]);
	return (count);
}
