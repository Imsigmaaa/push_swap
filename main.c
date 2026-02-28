/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/02/28 00:17:35 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include "ft_printf.h"

void	ft_stackclear(t_stack **lst)
{
	t_stack	*temp;
	t_stack	*next;

	if (!lst)
		return ;
	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

int	main(int argc, char **argv)
{
	char	**arr;
	t_stack	*stack_a;
	t_stack	*stack_b;

	arr = NULL;
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (0);
	if (argc == 2 && argv[1][0] == '\0')
		return (write(2, "Error\n", 6));
	arr = ft_parsing(argc, argv);
	if (!arr)
		return (0);
	stack_a = NULL;
	stack_b = NULL;
	stack_a = change_to_list(arr);
	if (!stack_a)
	{
		free(stack_a);
		return (0);
	}
	ft_stackclear(&stack_a);
	ft_stackclear(&stack_b);
	ft_free_arr(arr);
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
	free(dup);
	while (argv[1][i])
	{
		
	}
		return (write(1,"yes!\n",5));*/
		

