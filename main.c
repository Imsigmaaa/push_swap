/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/25 13:42:00 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

long	ft_atol(const char *nptr)
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
char	*ft_join(char *s1, char *s2, char c)
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
int	main(int argc, char ** argv)
{
	int	i;
	int	j;
	long a;
	long b;
	char *join = NULL;;
	char ** split = {NULL};
	
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (0);
	if(argc == 2 && argv[1][0] == '\0')
		return (write(2,"Error\n",6));
	

	//组合所有的元素、重新拆分
	i = 1;
	
	while (i < argc)
	{
		join = ft_join(join, argv[i], ' ');
		i ++;
	}
	
	split = ft_split(join, 32);
	i = 0;
	while(split[i])
	{
		printf("%s\n",split[i]);
		i ++;
	}
	
//判断是不是数字来输出error
	i = 0;
	while(split[i])
	{
		j = 0;
		while (split[i][j])
		{
			if(split[i][j] == '+' || split[i][j] == '-')
				j ++;
			if(!ft_isdigit(split[i][j]))
				return(write(2,"Error\n",6));
			while(ft_isdigit(split[i][j]))
				j ++;
			if(split[i][j] && !ft_isdigit(split[i][j]))
				return(write(2,"Error\n",6));	
		}
		i ++;
	}
	//判断有没有重复数字
	i = 0;
	while(split[i])
	{
		j = 0;
		a = ft_atol(split[i]);
		if(-2147483648 > a || a > 2147483647)
			return(write(2,"Error\n",6));
		while (split[j])
		{
			b = ft_atoi(split[j]);
			if(-2147483648 > b || b > 2147483647)
				return(write(2,"Error\n",6));
			if (a == b && i!=j)
				return(write(2,"Error\n",6));
			j ++;
		}
		i ++;
		
	}
	//判断INT是不是超MAX
	
		
		
		
		
		
		
		
		
		/*if(split[i][0] == '0')
			i ++;
		else
		{
			j = ft_atoi(split[i]);
			printf("%d\n", j);
			i ++;
			if (j == 0)
				return (write(2,"Error\n",6));
		}*/
	
	i = 0;
	while(split[i])
	{
		free(split[i]);
		i ++;
	}
	free(split);
	free(join);
}


	
	/*
	//判断array or string
while (argv[1][i] == 32 && argv[1][i])
	i ++;
while(argv[1][i] != 32 && argv[1][i])
	i ++;
while (argv[1][i] == 32 && argv[1][i])
	i ++;
if (argv[1][i] != 32 && argv[1][i])
{
	dup = ft_split(argv[1], 32);
	i = 0;
	while(dup[i])
	{
		printf("%s\n",dup[i]);
		i ++;
	}
	i = 0;
	while(dup[i])
	{
		free(dup[i]);
		i ++;
	}
	free(dup);
}
	//判断是否是数字
	i = ft_atoi(argv[1]);
	printf("%d", i);*/
	/*//解析成字符串组
	char **dup = ft_split(argv[1], 32);
	//测试是否有不可能转化成数字的字符串






	
	while(dup[i])
	{
		printf("%s\n",dup[i]);
		i ++;
	}
	i = 0;
	while(dup[i])
	{
		free(dup[i]);
		i ++;
	}
	free(dup);*/
	/*while (argv[1][i])
	{
		
	}
		return (write(1,"yes!\n",5));*/
		

