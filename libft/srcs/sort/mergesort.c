/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:35:14 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/28 14:35:16 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge(t_stack *a, t_stack *buf, int first, int last)
{
	int		i;
	int		mid;
	int		start;
	int		end;

	mid = first + (last - first) / 2;
	start = first;
	end = mid + 1;
	i = first;
	while (i <= last)
	{
		if ((start <= mid) &&
			((end > last) || (a->stack[start] < a->stack[end])))
			buf->stack[i] = a->stack[start++];
		else
			buf->stack[i] = a->stack[end++];
		i++;
	}
	i = first - 1;
	while (++i <= last)
		a->stack[i] = buf->stack[i];
}

static void	mergesort_(t_stack *a, t_stack *buf, int first, int last)
{
	int		mid;

	if (first < last)
	{
		mid = first + (last - first) / 2;
		mergesort_(a, buf, first, mid);
		mergesort_(a, buf, mid + 1, last);
		merge(a, buf, first, last);
	}
}

void		merge_sort(t_stack *a)
{
	t_stack	*buf;

	buf = stack_init(0, a->lenght, 0, 0);
	mergesort_(a, buf, 0, a->lenght - 1);
	stack_free(&buf);
}
