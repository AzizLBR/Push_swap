/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:01:21 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 19:34:47 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_choose_algo(t_stack *a, t_stack *b)
{
	if (ft_stack_is_sorted(a))
	{
		ft_free_stacks(&a);
		ft_free_stacks(&b);
		return ;
	}
	else if (a->len <= 3)
	{
		if (a->len == 3)
			ft_sort_three_numbers(a);
		else if (a->len == 2)
			if (a->numbers[0] > a->numbers[1])
				ft_swap_rule(a, 1);
	}
	else if (a->len > 3)
		ft_radix_sorting_method(a, b);
	ft_free_stacks(&a);
	ft_free_stacks(&b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = 0;
	b = 0;
	if (ac > 1)
	{
		if (!ft_split_arg(a, b, ac, av))
			return (-1);
	}
	return (0);
}
