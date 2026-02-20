/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 19:44:27 by xingchen          #+#    #+#             */
/*   Updated: 2025/11/19 22:49:20 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dup;
	unsigned int	i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
		i++;
	dup = malloc(i + 1);
	if (!dup)
		return (NULL);
	j = 0;
	while (s[j])
	{
		dup[j] = f(j, s[j]);
		j ++;
	}
	dup[j] = '\0';
	return (dup);
}
