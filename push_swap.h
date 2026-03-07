/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:45:35 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/07 03:14:35 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				post;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}	t_stack;

char	**ft_parsing(int ac, char **av);
t_stack	*change_to_list(char **arr, int *str);
t_stack	*stacklast(t_stack *head);
t_stack	*find_best_node(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_target_b(int index, t_stack **stack_b);
void	ft_free_arr(char **arr);
void	stackadd_front(t_stack **stack, t_stack *node);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stackswap(t_stack **stack);
void	find_best(t_stack **stack_a, t_stack **stack_b);
void	print_ab(t_stack **st_a, t_stack **st_b, t_stack *node);
int		count_post(t_stack **stack, t_stack *target);
int		count_len(t_stack **stack);
void	push_swap(t_stack **st_a, t_stack **st_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	swap_ab(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
int		*sort_numbers(char **arr, int *str);
long	ft_atol(char *nptr);
char	**stack_split(char const *s);
int		ft_strcmp(char *s1, char *s2);

void	ft_print_stack(t_stack *stack);
void	print_stack(t_stack **stack);
t_stack	*find_biggest_value(t_stack **stack);
void	recount_post(t_stack **stack);
int	calcul_len(char **arr);
void	ft_stackclear(t_stack **lst);

#endif