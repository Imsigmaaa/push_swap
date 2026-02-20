/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:48:29 by xingchen          #+#    #+#             */
/*   Updated: 2026/01/22 15:34:32 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putstr(char *c);
int	ft_putposition(void *position);
int	ft_putnbr(int n);
int	ft_putunbr(unsigned int n);
int	ft_print_hex(unsigned int n, char c);

#endif