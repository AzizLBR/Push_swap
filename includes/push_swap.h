/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 18:37:38 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 19:47:12 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int			len;
	int			*numbers;
}				t_stack;

t_stack	*ft_malloc_stacks(int len);
void	ft_free_stacks(t_stack **stack);
void	ft_choose_algo(t_stack *a, t_stack *b);
void	ft_swap_rule(t_stack *stack, int wich_stack);
void	ft_rotate_rule(t_stack *stack, int wich_stack);
void	ft_reverse_rotate_rule(t_stack *stack, int wich_stack);
void	ft_push_rule(t_stack *pushed_in, t_stack *push_to, int wich_stack);
void	ft_radix_sorting_method(t_stack *a, t_stack *b);
void	ft_sort_five_numbers(t_stack *a, t_stack *b, int pivot);
void	ft_sort_three_numbers(t_stack *stack);
int		ft_stack_is_sorted(t_stack *stack);
int		ft_is_digit_pushswap(char *str);
int		ft_check_double(char *str, int *num, int len);
int		ft_split_arg(t_stack *a, t_stack *b, int ac, char **av);
int		ft_get_pivot(t_stack *stack);
int		ft_check_str(char *str);
void	ft_free_tab(char **str);

#endif
