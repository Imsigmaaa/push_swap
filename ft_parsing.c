/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:24:06 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 12:13:14 by xingchen         ###   ########.fr       */
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
	{
		if (nptr[i] == '-')
			sign = -1;
		i ++;
	}
	while ('0' <= nptr[i] && nptr[i] <= '9')
	{
		result = result * 10 + (nptr[i] - '0');
		i ++;
	}
	return (result * sign);
}

int	is_error_digitdoule_and_extra(char **arr)
{
	int		j;
	int		i;
	long	a;
	long	b;

	i = 0;
	while (arr[i])
	{
		j = 0;
		a = ft_atol(arr[i]);
		if (-2147483648 > a || a > 2147483647)
			return (write(2, "Error\n", 6));
		while (arr[j])
		{
			b = ft_atoi(arr[j]);
			if (-2147483648 > b || b > 2147483647)
				return (write(2, "Error\n", 6));
			if (a == b && i != j)
				return (write(2, "Error\n", 6));
			j ++;
		}
		i ++;
	}
	return (0);
}

int	is_error_digital(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == '+' || arr[i][j] == '-')
				j ++;
			if (!ft_isdigit(arr[i][j]))
				return (write(2, "Error\n", 6));
			while (ft_isdigit(arr[i][j]))
				j ++;
			if (arr[i][j] && !ft_isdigit(arr[i][j]))
				return (write(2, "Error\n", 6));
		}
		i ++;
	}
	return (0);
}

char	*ft_strjoin_with_space(char *s1, char *s2, char c)
{
	size_t	s2_len;
	size_t	s1_len;
	char	*dup;

	if (!s1)
		s1_len = 0;
	else
		s1_len = ft_strlen(s1);
	if (!s2)
		s2_len = 0;
	else
		s2_len = ft_strlen(s2);
	dup = malloc(s1_len + s2_len + 2);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, s1_len);
	dup[s1_len] = c;
	ft_memcpy(dup + s1_len + 1, s2, s2_len);
	dup[s1_len + s2_len + 1] = '\0';
	free(s1);
	return (dup);
}

char	**ft_parsing(int ac, char **av)
{
	int		i;
	char	*join;
	char	**arr;

	join = NULL;
	arr = NULL;
	i = 1;
	if (ac == 2 && av[1][0] == '\0')
	{
		write(2, "Error\n", 6);
		return (NULL);
	}
	while (i < ac) //组合所有的元素、重新拆分
	{
		join = ft_strjoin_with_space(join, av[i], ' ');
		if (!join)
			return (free(join), NULL);
		i ++;
	}
	arr = ft_split(join, 32);
	if (!arr || is_error_digitdoule_and_extra(arr) || is_error_digital(arr))
		return (ft_free_arr(arr), NULL);
	return (free(join), arr);
}
