/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:03:11 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 22:03:13 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*fresh;
	size_t	i;

	if (len > len + 1)
		return (0);
	if (!s || (start > ft_strlen(s)))
		return (0);
	if (!(fresh = ft_strnew(len)))
		return (0);
	i = 0;
	while (i < len && s[start] != '\0')
	{
		fresh[i] = s[start];
		start++;
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
