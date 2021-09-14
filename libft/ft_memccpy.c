/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azizloubar <marvin@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:32:25 by azizlouba         #+#    #+#             */
/*   Updated: 2021/08/07 17:54:15 by aloubar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_c;
	unsigned char	*src_c;

	dst_c = (unsigned char *)dst;
	src_c = (unsigned char *)src;
	i = 0;
	while (i < n && src_c[i] != (unsigned char)c)
	{
		dst_c[i] = src_c[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		dst_c[i] = src_c[i];
		i++;
		return (&dst[i]);
	}
}
