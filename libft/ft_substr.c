/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen < xingchen@student.42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 19:29:48 by xingchen          #+#    #+#             */
/*   Updated: 2025/11/19 22:58:26 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_subcpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	size_t			s_len;
	size_t			size;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len < start)
		size = 1;
	else if (len < s_len - start)
		size = len + 1;
	else
		size = s_len - start + 1;
	sub = malloc(size);
	if (!sub)
		return (NULL);
	return (ft_subcpy(sub, s + start, size));
}
/*#include <stdio.h>
int main(void)
{
	char const s[] = "helloworld";
	char	*sub;
	int	i;
	sub = ft_substr(s,5,2);
	
	i = 0;
	while( i < 2)
	{	
		printf("%c",sub[i]);
		i ++;
	}
	free(sub);
}*/