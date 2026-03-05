/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:45:35 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/05 15:39:37 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				post;
	struct s_stack	*next;
}	t_stack;

char	**ft_parsing(int ac, char **av);
t_stack	*change_to_list(char **arr, int *str);
t_stack	*stacklast(t_stack *head);
t_stack	*find_target_a(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_target_b(int index, t_stack **stack_b);
void	ft_free_arr(char **arr);
void	stackadd_front(t_stack **stack, t_stack *node);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackswap(t_stack **stack);
void	find_best(t_stack **stack_a, t_stack **stack_b);
int		print_ab(t_stack **st_a, t_stack **st_b, t_stack *tag_a, t_stack *tag_b);
int		count_post(t_stack **stack, t_stack *target);
int		count_len(t_stack **stack);
int		push_swap(t_stack **st_a, t_stack **st_b);
int		push_a(t_stack **stack_a, t_stack **stack_b);
int		push_b(t_stack **stack_a, t_stack **stack_b);
int		swap_ab(t_stack **stack_a, t_stack **stack_b);
int		rotate_a(t_stack **stack_a);
int		rotate_b(t_stack **stack_b);
int		rotate_ab(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate_a(t_stack **stack_a);
int		reverse_rotate_b(t_stack **stack_b);
int		reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
int		*sort_numbers(char **arr, int *str);

void	ft_print_stack(t_stack *stack);
void	print_stack(t_stack **stack);
t_stack	*find_biggest_value(t_stack **stack);
void	recount_post(t_stack **stack);

#endif