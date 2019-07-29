/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:36:29 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/28 14:36:32 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	heapify(t_stack *a, int heap_size, int root_index)
{
	int		largest;
	int		left_child;
	int		right_child;

	largest = root_index;
	left_child = (2 * root_index) + 1;
	right_child = (2 * root_index) + 2;
	if (left_child < heap_size && a->stack[left_child] > a->stack[largest])
		largest = left_child;
	if (right_child < heap_size && a->stack[right_child] > a->stack[largest])
		largest = right_child;
	if (largest != root_index)
	{
		swap_elem(a, largest, root_index);
		heapify(a, heap_size, largest);
	}
}

void		heap_sort(t_stack *a)
{
	int		i;

	i = a->lenght - 1;
	while (i >= 0)
		heapify(a, a->lenght, i--);
	i = a->lenght - 1;
	while (i >= 0)
	{
		swap_elem(a, i, 0);
		heapify(a, i--, 0);
	}
}
