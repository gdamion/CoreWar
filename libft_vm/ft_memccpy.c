/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:02:28 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dst_ptr;
	unsigned char *src_ptr;
	unsigned char uns_c;

	dst_ptr = (unsigned char*)dst;
	src_ptr = (unsigned char*)src;
	uns_c = (unsigned char)c;
	while (n--)
	{
		if (*src_ptr == uns_c)
		{
			*dst_ptr++ = *src_ptr++;
			return (dst_ptr);
		}
		*dst_ptr++ = *src_ptr++;
	}
	return (NULL);
}
