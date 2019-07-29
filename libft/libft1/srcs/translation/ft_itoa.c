/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 22:48:45 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/23 22:48:58 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(long int nbr)
{
	int		len;
	char	*out;

	len = ft_nbrlen(nbr);
	out = ft_strnew(len);
	if (!nbr)
		out[0] = 48;
	if (nbr < 0)
	{
		out[0] = '-';
		nbr = -nbr;
	}
	while (--len >= 0 && nbr)
	{
		out[len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (out);
}
