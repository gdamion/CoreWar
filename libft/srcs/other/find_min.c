/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:54:29 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 21:54:31 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			find_min_(int *a, int lenght)
{
	int		i;
	int		min;

	i = 0;
	min = a[0];
	while (i < lenght)
	{
		if (a[i] < min)
			min = a[i];
		i++;
	}
	return (min);
}

int			index_min_(int *a, int lenght)
{
	int		i;
	int		min;
	int		index;

	i = 0;
	index = 0;
	min = a[0];
	while (i < lenght)
	{
		if (a[i] < min)
		{
			min = a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int			index_min(t_stack *a)
{
	return (index_min_(a->stack, a->lenght));
}

int			find_min(t_stack *a)
{
	return (find_min_(a->stack, a->lenght));
}
