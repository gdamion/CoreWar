/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:41:04 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/01 18:41:06 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dst_len;
	size_t	src_len;

	if (size > size + 1)
		return (0);
	i = ft_strlen(dst);
	j = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (size < i + 1)
		return (src_len + size);
	while (i < size - 1)
		*(dst + i++) = *(src + j++);
	*(dst + i) = '\0';
	return (dst_len + src_len);
}
