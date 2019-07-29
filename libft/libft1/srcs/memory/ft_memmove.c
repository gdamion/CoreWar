/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 18:22:21 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/20 18:22:22 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*fresh;
	unsigned char	*string;

	fresh = (unsigned char*)dst;
	string = (unsigned char*)src;
	if (fresh <= string || fresh >= (string + n))
	{
		while (n--)
			*fresh++ = *string++;
	}
	else
	{
		fresh += n - 1;
		string += n - 1;
		while (n--)
			*fresh-- = *string--;
	}
	return (dst);
}
