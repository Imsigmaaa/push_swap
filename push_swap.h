/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:45:35 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/04 14:46:13 by xingchen         ###   ########.fr       */
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
void	ft_free_arr(char **arr);
void	stackadd_front(t_stack **stack, t_stack *node);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackswap(t_stack **stack);
void	find_best(t_stack **stack_a, t_stack **stack_b);
//void	find_best(t_stack **stack_a, t_stack **stack_b);
int		push_a(t_stack **stack_a, t_stack **stack_b);
int		push_b(t_stack **stack_a, t_stack **stack_b);
int		swap_ab(t_stack **stack_a, t_stack **stack_b);
int		rotate_a(t_stack **stack_a);
int		rotate_b(t_stack **stack_b);
int		rotate_rr(t_stack **stack_a, t_stack **stack_b);
int		reverse_rotate_a(t_stack **stack_a);
int		reverse_rotate_b(t_stack **stack_b);
int		reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
int		*sort_numbers(char **arr, int *str);
#endif