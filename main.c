/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/26 17:17:42 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int		i;
	char	**arr;
	t_stack	*head;

	arr = NULL;
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (write(2, "Error\n", 6));
	arr = ft_parsing(argc, argv);
	if(!arr)
	{
		free(arr);
		return 0;
	}
	head = NULL;
	printf("%p\n", head);
	head = change_to_list(arr);
	if(!head)
	{
		free(head);
		return 0;
	}
	t_stack *test;
	test = head;
	while (test)
	{
		printf("33333:%d\n", test->value);
		test = test->next;
	}
	free(test);
	free(head);
	i = 0;
	while(arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}
	/*
	检查split后的字符串组
	while(arr[i])
	{
		printf("%s\n",arr[i]);
		i ++;
	}	
	*/
		
		
		
		
		
		
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
		

