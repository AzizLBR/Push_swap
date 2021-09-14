/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:43:02 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 18:08:42 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse_rotate_rule(t_stack *stack, int wich_stack)
{
	int		last_value;
	int		i;

	last_value = stack->numbers[stack->len - 1];
	i = stack->len - 1;
	while (i >= 1)
	{
		stack->numbers[i] = stack->numbers[i - 1];
		i--;
	}
	stack->numbers[0] = last_value;
	if (wich_stack == 1)
		printf("rra\n");
	else
		printf("rrb\n");
}

void	ft_rotate_rule(t_stack *stack, int wich_stack)
{
	int		first_value;
	int		i;

	first_value = stack->numbers[0];
	i = 0;
	while (i < stack->len - 1)
	{
		stack->numbers[i] = stack->numbers[i + 1];
		i++;
	}
	stack->numbers[i] = first_value;
	if (wich_stack == 1)
		printf("ra\n");
	else
		printf("rb\n");
}

void	ft_push_rule(t_stack *pushed_in, t_stack *push_to, int wich_stack)
{
	int		i;

	i = pushed_in->len - 1;
	while (i >= 0)
	{
		pushed_in->numbers[i + 1] = pushed_in->numbers[i];
		i--;
	}
	pushed_in->numbers[0] = push_to->numbers[0];
	pushed_in->len++;
	i = 0;
	while (i < push_to->len - 1)
	{
		push_to->numbers[i] = push_to->numbers[i + 1];
		i++;
	}
	push_to->len--;
	if (wich_stack == 1)
		printf("pa\n");
	else
		printf("pb\n");
}

void	ft_swap_rule(t_stack *stack, int wich_stack)
{
	int		swapped_value;

	swapped_value = stack->numbers[0];
	stack->numbers[0] = stack->numbers[1];
	stack->numbers[1] = swapped_value;
	if (wich_stack == 1)
		printf("sa\n");
	else
		printf("sb\n");
}
