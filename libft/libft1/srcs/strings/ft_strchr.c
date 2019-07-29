/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:40:55 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 17:40:57 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;
	int len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		if (str[i] == (char)c)
			return ((char*)(&str[i]));
		i++;
	}
	return (0);
}
