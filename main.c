/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 02:52:45 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	isdigit_double(char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[j])
		{
			if(i != j && ft_strcmp(arr[i], arr[j]) == 0)
				return (1);
			j ++;
		}
		i ++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	**arr;
	int		*str;
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	str = NULL;
	if (argc == 1)
		return (0);
	arr = NULL;
	arr = ft_parsing(argc, argv);
	if (!arr || isdigit_double(arr))
	{
		write(2, "Error\n", 6);
		return (ft_free_arr(arr), 0);
	}
	str = sort_numbers(arr, str);
	if (!str)
		return (ft_stackclear(&stack_a), free(str), 0);
	stack_a = change_to_list(arr, str);
	if (!stack_a)
		return (ft_stackclear(&stack_a), free(str), 0);
	push_swap(&stack_a, &stack_b);
	return ( ft_stackclear(&stack_a), ft_stackclear(&stack_b), 0);
}
	//检查split后的字符串组
	/*while(arr[i])
	{
		printf("%s\n",arr[i]);
		i ++;
	}	
	
			
		if(split[i][0] == '0')
			i ++;
		else
		{
			j = ft_atoi(split[i]);
			printf("%d\n", j);
			i ++;
			if (j == 0)
				return (write(2,"Error\n",6));
		}
	
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
	printf("%d", i);
	//解析成字符串组
	char **dup = ft_split(argv[1], 32);
	测试是否有不可能转化成数字的字符串

	
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


/*测试转换	
int a = push_b(&stack_a,&stack_b);
	printf("--------PUSH----------------------\n");
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	a = push_b(&stack_a,&stack_b);
	printf("---------PUSH---------------------\n");
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	printf("----------SWAP--------------------\n");
	a = swap_ab(&stack_a,&stack_b);
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	printf("------------RR------------------\n");
	int b = rotate_rr(&stack_a,&stack_b);
	printf("------------------------------\n");
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	printf("-------------RRR-----------------\n");
	b = reverse_rotate_ab(&stack_a,&stack_b);
	printf("------------------------------\n");
	ft_print_stack(stack_a);
	ft_print_stack(stack_b);
	printf("------------------------------\n");
	printf("%d%d\n",a,b);*/

	/*打印 一
	void ft_print_stack(t_stack *stack)
{
	t_stack *temp;

	temp = stack;
	if(!temp)
		printf("null\n");
	while (temp)
	{
		printf("value=%d,index=%d, post =%d\n",temp->value,temp->index,temp->post);
		temp = temp->next;
	}
}*/
/*打印二
void	print_stack(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	if (!temp)
		printf("null\n");
	while (temp)
	{
		printf ("value=%d, index=%d, post=%d\n", temp->value, temp->index, temp->post);
		temp = temp->next;
	}
}
*/