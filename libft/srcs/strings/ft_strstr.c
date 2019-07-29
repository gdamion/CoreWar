/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:58:01 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 17:58:02 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strstr(const char *str, const char *sub)
{
	size_t	n;

	n = ft_strlen((char*)sub);
	if (n == 0)
		return ((char*)(str));
	while (*str)
		if (!ft_memcmp(str++, sub, n))
			return ((char*)(str - 1));
	return (0);
}
