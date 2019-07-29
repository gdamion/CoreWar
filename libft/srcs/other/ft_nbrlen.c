/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:54:29 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 21:54:31 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbrlen(long long int nb)
{
	int	size;

	size = 1;
	if (nb < 0)
	{
		size++;
		nb = -nb;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

int		ft_nbrlen_u(unsigned long long nb)
{
	int	size;

	size = 1;
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}
