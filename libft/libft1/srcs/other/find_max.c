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

int			find_max_(int *a, int lenght)
{
	int		i;
	int		max;

	i = 0;
	max = a[0];
	while (i < lenght)
	{
		if (a[i] > max)
			max = a[i];
		i++;
	}
	return (max);
}

int			index_max_(int *a, int lenght)
{
	int		i;
	int		max;
	int		index;

	i = 0;
	max = a[0];
	index = 0;
	while (i < lenght)
	{
		if (a[i] > max)
		{
			max = a[i];
			index = i;
		}
		i++;
	}
	return (index);
}

int			index_max(t_stack *a)
{
	return (index_max_(a->stack, a->lenght));
}

int			find_max(t_stack *a)
{
	return (find_max_(a->stack, a->lenght));
}

int			find_abs_max(t_stack *a)
{
	int		i;
	t_stack	*b;
	int		out;

	i = 0;
	b = stack_init(a->id, a->lenght, 0, a->debug);
	while (i < a->lenght)
	{
		b->stack[i] = FT_ABS(a->stack[i]);
		i++;
	}
	out = find_max_(b->stack, b->lenght);
	stack_free(&b);
	return (out);
}
