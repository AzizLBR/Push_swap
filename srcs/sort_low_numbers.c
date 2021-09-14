/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_low_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:16:28 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 18:48:53 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three_numbers(t_stack *stack)
{
	if (stack->numbers[0] < stack->numbers[1]
		&& stack->numbers[1] > stack->numbers[2])
	{
		ft_reverse_rotate_rule(stack, 1);
		if (stack->numbers[0] < stack->numbers[2]
			&& (!ft_stack_is_sorted(stack)))
			ft_swap_rule(stack, 1);
	}
	else if (stack->numbers[0] > stack->numbers[1]
		&& stack->numbers[1] > stack->numbers[2])
	{
		ft_swap_rule(stack, 1);
		ft_reverse_rotate_rule(stack, 1);
	}
	else if (stack->numbers[0] > stack->numbers[1]
		&& stack->numbers[1] < stack->numbers[2])
	{
		if (stack->numbers[0] > stack->numbers[2])
			ft_rotate_rule(stack, 1);
		else
			ft_swap_rule(stack, 1);
	}
}

static void	ft_empty_b_stack(t_stack *a, t_stack *b)
{
	if (b->numbers[0] < b->numbers[1])
		ft_swap_rule(b, 2);
	while (b->len > 0)
		ft_push_rule(a, b, 1);
}

void	ft_sort_five_numbers(t_stack *a, t_stack *b, int pivot)
{
	int		i;
	int		j;

	i = -1;
	while (a->len > 3)
	{
		if (a->numbers[0] < pivot)
			ft_push_rule(b, a, 2);
		else if (a->numbers[++i] < pivot)
		{
			if (i <= a->len - i)
			{
				while (i-- > 0)
					ft_rotate_rule(a, 1);
			}
			else
			{
				j = a->len - i + 1;
				while (--j > 0)
					ft_reverse_rotate_rule(a, 1);
			}
		}
	}
	ft_sort_three_numbers(a);
	ft_empty_b_stack(a, b);
}
