/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:23:17 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:13:55 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i ++;
	}
	free(arr);
}

int	is_sort_stack(t_stack **stack)
{
	t_stack	*temp;
	int		i;
	int		len;

	i = 0;
	len = stack_size(stack);
	temp = *stack;
	while (temp && i < len)
	{
		if (temp->index != i)
			return (0);
		i ++;
		temp = temp->next;
	}
	return (1);
}

int	is_all_space(char **args)
{
	int	i;
	int	j;

	if (!args || !args[0])
		return (1);
	i = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j] && (args[i][j] == ' ' 
			|| (args[i][j] >= 9 && args[i][j] <= 13)))
			j ++;
		if (args[i][j] == '\0')
			return (1);
		i ++;
	}
	return (0);
}

void	push_swap(t_stack **a, t_stack **b)
{
	t_stack	*node;

	if (is_sort_stack(a))
		return ;
	small_sort(a, b);
	if (!*b)
		return ;
	while (*b)
	{
		set_position(a);
		set_position(b);
		set_target(a, b);
		set_cost(a, b);
		node = find_best_node(a, b);
		rotate_for_push_a(a, b, node);
		push_a(a, b);
	}
	sort_stack(a);
	return ;
}

int	main(int argc, char **argv)
{
	char	**tokens;
	int		*str;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (is_all_space(argv))
		return (write(2, "Error\n", 6), 0);
	tokens = ft_parsing(argc, argv);
	if (!tokens)
		return (write(2, "Error\n", 6), 0);
	str = ft_sort_numbers(tokens);
	if (!str)
		return (stack_clear(&a), 0);
	a = create_stack(tokens, str);
	if (!a)
		return (stack_clear(&a), free(str), 0);
	push_swap(&a, &b);
	return (stack_clear(&a), stack_clear(&b), 0);
}
//ft_print_stack(stack_a);
	//ft_print_stack(stack_b);	
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
	
}*/
