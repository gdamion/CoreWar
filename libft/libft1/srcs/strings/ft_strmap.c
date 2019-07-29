/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 20:06:25 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 20:06:27 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*fresh;

	i = 0;
	fresh = 0;
	if (s && f)
		if ((fresh = ft_strnew(ft_strlen(s))))
			while (s[i])
			{
				fresh[i] = f((char)s[i]);
				i++;
			}
	return (fresh);
}
