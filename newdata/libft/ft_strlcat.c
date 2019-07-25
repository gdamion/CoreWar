/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:05:18 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*dst_ptr;
	const char	*src_ptr;
	size_t		dst_len;
	size_t		tmp_len;

	dst_ptr = (char*)dst;
	src_ptr = src;
	tmp_len = size;
	while (tmp_len-- && *dst_ptr)
		dst_ptr++;
	dst_len = dst_ptr - dst;
	tmp_len = size - dst_len;
	if (!tmp_len)
		return (dst_len + ft_strlen(src_ptr));
	while (*src_ptr)
	{
		if (tmp_len != 1)
		{
			*dst_ptr++ = *src_ptr;
			tmp_len--;
		}
		src_ptr++;
	}
	*dst_ptr = '\0';
	return (dst_len + (src_ptr - src));
}
