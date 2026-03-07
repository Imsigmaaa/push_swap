/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:24:06 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/06 20:01:16 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(int len, char *str)
{
	int		i;
	long	a;

	i = 0;
	while (i < len && (str[i] == 32 || (9 <= str[i] && str[i] <= 13)))
		i ++;
	if (i == len)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i ++;
	if (i == len)
		return (0);
	while (i < len && str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i ++;
	}
	a = ft_atol(str);
	if (-2147483648 > a || a > 2147483647)
		return (0);
	return (1);
}

int	check_arr_isnumber(char **arr)
{
	int	i;
	int	len;

	i = 0;
	while (arr[i])
	{
		len = ft_strlen(arr[i]);
		if (!is_number(len, arr[i]))
			return (0);
		i ++;
	}
	i = 0;
	
	return (1);
}

char	**copy_av(int ac, char **arr, char **av)
{
	int	i;
	int	k;

	i = 1;
	k = 0;
	arr = malloc(sizeof(char *) * ac);
	if (!arr)
		return (NULL);
	while (i < ac)
	{
		if (av[i][0] != '\0')
		{
			arr[k] = av[i];
			k ++;
		}
		i ++;
	}
	arr[k] = NULL;
	return (arr);
}

char	*ft_strjoin_with_space(char *join, char *s1)
{
	char	*dup;
	char	*temp;
	char	*space;

	space = " ";
	if (!join)
		dup = ft_strdup(s1);
	else
	{
		temp = ft_strjoin(join, space);
		free (join);
		if (!temp)
			return (NULL);
		dup = ft_strjoin(temp, s1);
		free (temp);
	}
	if (!dup)
		return (NULL);
	return (dup);
}

char	**ft_parsing(int ac, char **av)
{
	int		i;
	char	*join;
	char	**arr;
	char	**tab;

	if (ac == 2 && av[1][0] == '\0')
		return (NULL);
	join = NULL;
	arr = NULL;
	arr = copy_av(ac, arr, av);
	if (!arr)
		return (NULL);
	i = 0;
	while (arr[i]) //组合所有的元素、重新拆分
	{
		join = ft_strjoin_with_space(join, arr[i]);
		if (!join)
			return (free(arr), NULL);
		i ++;
	}
	tab = stack_split(join);
	if (!tab || !check_arr_isnumber(tab))
		return (free(arr), ft_free_arr(tab), NULL);
	return (free(arr), free(join), tab);
}
