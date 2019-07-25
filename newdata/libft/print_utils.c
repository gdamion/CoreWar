/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:10:22 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		l_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

long	calc_len(long n, long count)
{
	if (n < 0)
	{
		count++;
		n *= -1;
	}
	if (n > 9)
	{
		calc_len(n / 10, count);
		count++;
	}
	return (count);
}

void	set_width(const char *fmt, t_fmt *f)
{
	if (ft_isdigit(fmt[f->i]))
	{
		f->field_width = ft_atoi(&fmt[f->i]);
	}
	while (ft_isdigit(fmt[f->i]))
		(f->i)++;
}
