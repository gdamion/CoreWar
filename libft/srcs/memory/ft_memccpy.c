/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 17:42:57 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/20 17:43:01 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*sour;

	i = 0;
	dest = (unsigned char*)dst;
	sour = (unsigned char*)src;
	while (i < n)
	{
		dest[i] = sour[i];
		if (sour[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (0);
}
