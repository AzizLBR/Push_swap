/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:26:50 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 18:50:06 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_is_sorted(t_stack *stack)
{
	int		i;
	int		j;

	i = 0;
	while (i < stack->len)
	{
		j = i + 1;
		while (j < stack->len)
		{
			if (stack->numbers[i] > stack->numbers[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_is_digit_pushswap(char *str)
{
	int		i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (0);
	return (1);
}

int	ft_check_double(char *str, int *numbers, int len)
{
	int		num;
	int		i;

	i = -1;
	if (!str)
		return (0);
	num = ft_atoi(str);
	while (++i < len)
		if (numbers[i] == num)
			return (0);
	return (1);
}

int	ft_get_pivot(t_stack *stack)
{
	int		i;
	int		j;
	int		left_side;
	int		right_side;
	int		pivot;

	i = 0;
	left_side = 0;
	right_side = 1;
	while (right_side != left_side)
	{
		right_side = !(stack->len % 2);
		left_side = 0;
		pivot = stack->numbers[i];
		j = -1;
		while (++j < stack->len)
		{
			if (pivot > stack->numbers[j])
				left_side++;
			else if (pivot < stack->numbers[j])
				right_side++;
		}
		i++;
	}
	return (pivot);
}

int	ft_check_str(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if ((str[i] == '-' || str[i] == '+')
			&& (str[i + 1] < '0' || str[i + 1] > '9'))
			return (0);
	return (1);
}
