/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xingchen <xingchen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/20 12:45:35 by xingchen          #+#    #+#             */
/*   Updated: 2026/03/13 16:28:07 by xingchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

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

t_stack	*create_stack(char **arr, int *str);
t_stack	*find_best_node(t_stack **a, t_stack **b);
char	**ft_parsing(int ac, char **av);
char	**ft_split_tokens(char const *s);
int		*ft_sort_numbers(char **arr);
int		stack_size(t_stack **stack);
long	ft_atol(char *nptr);
void	set_target(t_stack **a, t_stack **b);
void	set_cost(t_stack **a, t_stack **b);
void	rotate_for_push_a(t_stack **a, t_stack **b, t_stack *node);
void	set_position(t_stack **stack);
void	ft_free_arr(char **arr);
void	stackadd_front(t_stack **stack, t_stack *node);
void	stackadd_back(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **lst);
void	push_swap(t_stack **a, t_stack **b);
void	push_a(t_stack **a, t_stack **b);
void	push_b(t_stack **a, t_stack **b);
void	swap_ab(t_stack **a, t_stack **b);
void	swap_a(t_stack **a);
void	swap_b(t_stack **b);
void	rotate_a(t_stack **a);
void	rotate_b(t_stack **b);
void	rotate_ab(t_stack **a, t_stack **b);
void	reverse_rotate_a(t_stack **a);
void	reverse_rotate_b(t_stack **b);
void	reverse_rotate_ab(t_stack **a, t_stack **b);
void	small_sort(t_stack **a, t_stack **b);
void	sort_stack(t_stack **stack);

#endif