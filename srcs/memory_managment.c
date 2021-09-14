/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_managment.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 15:03:20 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 16:53:57 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_malloc_stacks(int len)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (stack == NULL)
	{
		ft_putendl_fd("Error", 2);
		exit(0);
	}
	stack->len = len;
	if (len > 0)
	{
		stack->numbers = (int *)malloc(sizeof(int) * len);
		if (stack->numbers == NULL)
		{
			ft_putendl_fd("Error", 2);
			exit (0);
		}
	}
	else
		stack->numbers = 0;
	return (stack);
}

void	ft_free_stacks(t_stack **stack)
{
	if (*stack)
	{
		free((*stack)->numbers);
		(*stack)->numbers = 0;
		free(*stack);
		*stack = 0;
	}
}

void	ft_free_tab(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		free(str[i]);
	free(str);
}
