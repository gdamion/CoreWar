/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:47:58 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 17:48:02 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strncat(char *dst, const char *src, size_t num)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (num > num + 1)
		return (0);
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0' && j < num)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}
