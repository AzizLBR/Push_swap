/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <aloubar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 14:58:46 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 19:51:43 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_sort_stock_stack(t_stack *stocks, t_stack *a)
{
	int		i;
	int		swapped_value;

	i = -1;
	while (++i < a->len)
		stocks->numbers[i] = a->numbers[i];
	i = 0;
	while (i < stocks->len - 1)
	{
		if (stocks->numbers[i] > stocks->numbers[i + 1])
		{
			swapped_value = stocks->numbers[i];
			stocks->numbers[i] = stocks->numbers[i + 1];
			stocks->numbers[i + 1] = swapped_value;
			i = 0;
		}
		else
			i++;
	}
}

static void	ft_sort_big_numbers(t_stack *a, t_stack *b)
{
	int		size;
	int		i;
	int		j;

	size = a->len;
	i = 0;
	while (!ft_stack_is_sorted(a))
	{
		j = -1;
		while (++j < size)
		{
			if (((a->numbers[0] >> i) & 1) == 1)
				ft_rotate_rule(a, 1);
			else
				ft_push_rule(b, a, 2);
		}
		while (b->len > 0)
			ft_push_rule(a, b, 1);
		i++;
	}
}

static void	ft_change_nbvalue(t_stack *a, t_stack *stocks)
{
	int		i;
	int		j;

	i = -1;
	while (++i < a->len)
	{
		j = -1;
		while (++j < stocks->len)
		{
			if (a->numbers[i] == stocks->numbers[j])
			{
				a->numbers[i] = j;
				break ;
			}
		}
	}
}

void	ft_radix_sorting_method(t_stack *a, t_stack *b)
{
	t_stack		*stocks;

	stocks = ft_malloc_stacks(a->len);
	ft_sort_stock_stack(stocks, a);
	ft_change_nbvalue(a, stocks);
	if (a->len == 5)
		ft_sort_five_numbers(a, b, ft_get_pivot(a));
	else
		ft_sort_big_numbers(a, b);
	ft_free_stacks(&stocks);
}
