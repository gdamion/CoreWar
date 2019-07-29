/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:41:54 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 20:41:57 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char				*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	i = 0;
	fresh = 0;
	if (s && f)
		if ((fresh = ft_strnew(ft_strlen(s))))
			while (s[i])
			{
				fresh[i] = f(i, (char)s[i]);
				i++;
			}
	return (fresh);
}
