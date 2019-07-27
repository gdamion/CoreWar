/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reversestr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:04:13 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_reversestr(char *str)
{
	int		len;
	int		i;
	char	tmp;

	if (!str)
		return ;
	i = 0;
	len = ft_strlen(str) - 1;
	while (i < len)
	{
		tmp = str[i];
		str[i] = str[len];
		str[len] = tmp;
		i++;
		len--;
	}
}
