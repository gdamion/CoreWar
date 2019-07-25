/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:02:48 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned const char	*src_tmp;
	unsigned char		*dst_tmp;

	dst_tmp = dst;
	src_tmp = src;
	if (dst > src)
	{
		while (len--)
		{
			dst_tmp[len] = src_tmp[len];
		}
	}
	else if (src > dst)
		ft_memcpy(dst, src, len);
	return (dst);
}
