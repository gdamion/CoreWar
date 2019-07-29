/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 22:55:42 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 22:55:43 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	char	*fresh;

	ret = 0;
	if (s1 && s2 && (fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
	{
		ret = fresh;
		while (*s1)
			*fresh++ = (char)*s1++;
		while (*s2)
			*fresh++ = (char)*s2++;
	}
	return (ret);
}
