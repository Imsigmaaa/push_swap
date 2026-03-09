/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 11:24:06 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/09 06:50:36 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**copy_avgs(int ac, char **avgs)
{
	int	i;
	int	k;
	char **avgs_cp;

	i = 1;
	k = 0;
	avgs_cp = malloc(sizeof(char *) * ac);
	if (!avgs_cp)
		return (NULL);
	while (i < ac)
	{
		if (avgs[i][0] != '\0')
		{
			avgs_cp[k] = avgs[i];
			k ++;
		}
		i ++;
	}
	avgs_cp[k] = NULL;
	return (avgs_cp);
}

char	*ft_args_join(char *joined_args, char *s1)
{
	char	*dup;
	char	*temp;
	char	*space;

	space = " ";
	if (!joined_args)
		dup = ft_strdup(s1);
	else
	{
		temp = ft_strjoin(joined_args, space);
		free (joined_args);
		if (!temp)
			return (NULL);
		dup = ft_strjoin(temp, s1);
		free (temp);
	}
	if (!dup)
		return (NULL);
	return (dup);
}

int	is_number(char **tokens)
{
	int		i;
	int		j;

	i = 0;
	while (tokens[i])
	{
		j = 0;
		if(tokens[i][j] == '+' || tokens[i][j] == '-')
			j ++;
		if(!tokens[i][j])
			return	(0);
		while (tokens[i][j])
		{
			if (!ft_isdigit(tokens[i][j]))
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

int	is_double_or_extra(char **arr)
{
	int		i;
	int		j;
	long	a;
	long	b;

	i = 0;
	while (arr[i])
	{
		j = 0;
		a = ft_atol(arr[i]);
		while (arr[j])
		{
			b = ft_atol(arr[j]);
			if (b < -2147483648 || b > 2147483647)
				return (0);
			if(i != j && a == b)
				return (0);
			j ++;
		}
		i ++;
	}
	return (1);
}

char	**ft_parsing(int ac, char **av)
{
	int		i;
	char	*joined_args;
	char	**args_cp;
	char	**tokens;

	joined_args = NULL;
	args_cp = copy_avgs(ac, av);
	if (!args_cp)
		return (NULL);
	i = 0;
	while (args_cp[i]) //组合所有的元素、重新拆分
	{
		joined_args = ft_args_join(joined_args, args_cp[i]);
		if (!joined_args)
			return (free(args_cp), NULL);
		i ++;
	}
	tokens = ft_split_tokens(joined_args);
	if (!tokens || !is_number(tokens) || !is_double_or_extra(tokens))
		return (free(args_cp),free(joined_args), ft_free_arr(tokens), NULL);
	return (free(args_cp), free(joined_args), tokens);
}
