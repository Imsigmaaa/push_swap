/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 19:31:59 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/22 16:39:33 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

int	is_print(const char *c, va_list *args)
{
	if (*(c) == 'c')
		return (ft_putchar(va_arg(*args, int)));
	if (*(c) == 's')
		return (ft_putstr(va_arg(*args, char *)));
	if (*(c) == 'p')
		return (ft_putposition(va_arg(*args, void *)));
	if (*(c) == 'd')
		return (ft_putnbr(va_arg(*args, int)));
	if (*(c) == 'i')
		return (ft_putnbr(va_arg(*args, int)));
	if (*(c) == 'u')
		return (ft_putunbr(va_arg(*args, unsigned int)));
	if (*(c) == 'x')
		return (ft_print_hex(va_arg(*args, unsigned int), *c));
	if (*(c) == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), *c));
	if (*(c) == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list			args;
	unsigned int	i;

	va_start(args, format);
	i = 0;
	if (!format || *format == 0)
		return (0);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			i = i + is_print(format, &args);
		}
		else
			i = i + ft_putchar(*format);
		format ++;
	}
	va_end(args);
	return (i);
}
/*#include <stdio.h>
int main(void)
{*/
	/*int n = ft_printf("1=%c2=%c3=%c\n",97,300,-2);
	int m = printf("1=%c2=%c3=%c\n",97,300,-2);
	ft_printf("n=%dm=%d\n", n,m);
	printf("n=%dm=%d", n,m);*/
	/*char *str = NULL;
	int n = ft_printf("1=%d 2=%d 3=%d 4=%d 5=%d\n",1,-55,"hello","",str);
	int o = ft_printf("1=%i 2=%i 3=%i 4=%i 5=%i\n",1,-55,"hello","",str);
	int m = printf("1=%d 2=%d 3=%d 4=%d 5=%d\n",1,-55,"hello","",str);
	int p = printf("1=%i 2=%i 3=%i 4=%i 5=%i\n",1,-55,"hello","",str);
	ft_printf("n=%d o=%d m=%d p=%d\n", n,o,m,p);
	printf("n=%d o=%d m=%d p=%d\n", n,o,m,p);*/
	/*char *str = NULL;
	int n = ft_printf("1=%s  2=%s3=%s\n","hello","",str);
	int m = printf("1=%s  2=%s3=%s\n","hello","",str);
	ft_printf("n=%dm=%d\n", n,m);
	printf("n=%dm=%d", n,m);*/
	/*char *str = NULL;
	int n = ft_printf("1=%p  2=%p3=%p\n","hello","",str);
	int m = printf("1=%p  2=%p3=%p\n","hello","",str);
	ft_printf("n=%dm=%d\n", n,m);
	printf("n=%dm=%d", n,m);*/
	/*char *str = NULL;
	int n = ft_printf("1=%u 2=%u 3=%u 4=%u 5=%u\n",1,-55,"hello","",str);
	int m = printf("1=%u 2=%u 3=%u 4=%u 5=%u\n",1,-55,"hello","",str);
	ft_printf("n=%dm=%d\n", n,m); 
	printf("n=%dm=%d", n,m);*/
	/*char *str = NULL;
	int n = ft_printf("1=%x 2=%x 3=%x 4=%x 5=%x 6=%x\n",1,-55,55,"hello","",str);
	int o = ft_printf("1=%X 2=%X 3=%X 4=%X 5=%X 6=%X\n",1,-55,55,"hello","",str);
	int m = printf("1=%x 2=%x 3=%x 4=%x 5=%x 6=%x\n",1,-55,55,"hello","",str);
	int p = ft_printf("1=%X 2=%X 3=%X 4=%X 5=%X 6=%X\n",1,-55,55,"hello","",str);
	ft_printf("n=%do=%dm=%dp=%d\n", n,o,m,p); 
	printf("n=%do=%dm=%dp=%d\n",  n,o,m,p);*/
	/*int n = ft_printf("1=%%\n");
	int m = printf("1=%%\n");
	ft_printf("n=%dm=%d\n", n,m);
	printf("n=%dm=%d", n,m);*/

//}