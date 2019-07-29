/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selectionsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 14:36:57 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/28 14:37:03 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	selection_sort(t_stack *a)
{
	int	i;
	int	j;
	int	lowest_value_index;

	i = 0;
	while (i < a->lenght)
	{
		lowest_value_index = i;
		j = i;
		while (++j < a->lenght)
			if (a->stack[j] < a->stack[lowest_value_index])
				lowest_value_index = j;
		swap_elem(a, i, lowest_value_index);
		i++;
	}
}
