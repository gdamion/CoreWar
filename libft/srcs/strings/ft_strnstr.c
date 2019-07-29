/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 19:13:24 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 19:13:25 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strnstr(const char *str, const char *sub, size_t len)
{
	size_t	sub_l;

	if (str == sub || *sub == '\0' || !(sub_l = ft_strlen(sub)))
		return ((char*)(str));
	while (*str && len-- >= sub_l)
	{
		if ((*str == *sub) && ft_strncmp(str, sub, sub_l) == 0)
			return ((char*)str);
		str++;
	}
	return (0);
}
