/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:57:23 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 21:57:31 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_stack		*stackcpy(t_stack *a)
{
	int		i;
	t_stack	*b;

	i = 0;
	b = stack_init(a->id, a->lenght, 0, a->debug);
	while (i < a->lenght)
	{
		b->stack[i] = a->stack[i];
		i++;
	}
	return (b);
}

void		mid(t_stack *a)
{
	int		i;
	int		j;
	t_stack	*b;
	int		lowest_value_index;

	i = 0;
	b = stackcpy(a);
	while (i <= b->lenght / 2)
	{
		lowest_value_index = i;
		j = i;
		while (++j < b->lenght)
			if (b->stack[j] < b->stack[lowest_value_index])
				lowest_value_index = j;
		swap_elem(b, i, lowest_value_index);
		i++;
	}
	a->mid = b->stack[i - 1];
	stack_free(&b);
}

int			is_sorted(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (b->lenght)
		return (0);
	while (++i < a->lenght)
		if (a->stack[i - 1] > a->stack[i])
			return (0);
	return (1);
}

void		is_sort(t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (b->lenght)
		print_error(ERR_CHECKER);
	while (++i < a->lenght)
		if (a->stack[i - 1] > a->stack[i])
			print_error(ERR_CHECKER);
	ft_printf(CHECKER_OK);
}
