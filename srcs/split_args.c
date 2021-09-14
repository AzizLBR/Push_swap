/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubar <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 14:59:42 by aloubar           #+#    #+#             */
/*   Updated: 2021/09/14 18:32:25 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static char	**ft_join_and_split(char **av, int ac)
{
	int		i;
	char	*str;
	char	**args;

	if (ac > 2)
	{
		str = ft_strjoin(av[1], av[2]);
		i = 2;
		while (av[++i])
			str = ft_strjoin(str, av[i]);
		if (!ft_check_str(str))
		{
			free(str);
			ft_putendl_fd("Error", 2);
			return (NULL);
		}
		args = ft_split(str, ' ');
		free(str);
	}
	else
		args = ft_split(av[1], ' ');
	return (args);
}

static	int	ft_args_to_int_tab(char **args, t_stack *a, t_stack *b)
{
	int	i;

	i = -1;
	while (args[++i])
	{
		if (!(ft_check_double(args[i], a->numbers, i)))
		{
			ft_free_stacks(&a);
			ft_free_stacks(&b);
			ft_free_tab(args);
			ft_putendl_fd("Error", 2);
			return (0);
		}
		a->numbers[i] = ft_atoi(args[i]);
	}
	return (1);
}

int	ft_split_arg(t_stack *a, t_stack *b, int ac, char **av)
{
	int		i;
	char	**args;

	args = ft_join_and_split(av, ac);
	if (args == NULL)
		return (0);
	i = -1;
	while (args[++i])
	{
		if (!ft_is_digit_pushswap(args[i]))
		{
			ft_free_tab(args);
			ft_putendl_fd("Error", 2);
			return (0);
		}
	}
	a = ft_malloc_stacks(i);
	b = ft_malloc_stacks(i);
	b->len = 0;
	if (!ft_args_to_int_tab(args, a, b))
		return (0);
	ft_free_tab(args);
	ft_choose_algo(a, b);
	return (1);
}
