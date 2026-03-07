/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 16:00:42 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/06 17:43:34 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_space(char c)
{
	int		i;
	char	s[7];

	s[0] = 9;
	s[1] = 10;
	s[2] = 11;
	s[3] = 12;
	s[4] = 13;
	s[5] = 32;
	s[6] = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] && s[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

static int	count_words(char const *s)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && is_space(s[i]))
			i ++;
		if (s[i] && !is_space(s[i]))
		{
			count ++;
			i ++;
			while (s[i] && !is_space(s[i]))
				i ++;
		}
	}
	return (count);
}

static char	*cpy_words(char const *s, int *dup_j_len)
{
	int		j;
	char	*temp;

	while (s[*dup_j_len] && !is_space(s[*dup_j_len]))
		(*dup_j_len)++;
	temp = malloc(*dup_j_len + 1);
	if (!temp)
		return (NULL);
	j = 0;
	while (j < *dup_j_len)
	{
		temp[j] = s[j];
		j ++;
	}
	temp[j] = '\0';
	return (temp);
}

static	char	*fill_array(char **dup, char const *s, int *index)
{
	int	dup_i_len;

	*dup = NULL;
	while (s[*index] && is_space(s[*index]))
		(*index)++;
	dup_i_len = 0;
	if (s[*index] && !is_space(s[*index]))
	{
		(*dup) = cpy_words(s + *index, &dup_i_len);
		if (!(*dup))
			return (NULL);
	}
	*index = *index + dup_i_len;
	return (*dup);
}

char	**stack_split(char const *s)
{
	char	**dup;
	int		dup_len;
	int		index;
	int		j;

	if (!s)
		return (NULL);
	dup_len = count_words(s);
	dup = (char **)malloc(sizeof(char *) * (dup_len + 1));
	if (!dup)
		return (NULL);
	index = 0;
	j = 0;
	while (s[index] && j < dup_len)
	{
		fill_array(&dup[j], s, &index);
		if (!dup[j])
			return (ft_free_arr(dup), NULL);
		j ++;
	}
	dup[dup_len] = NULL;
	return (dup);
}
