/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:09:00 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	write_left_align(t_fmt *f, int n)
{
	if (f->zero)
	{
		while (f->field_width-- > 1)
			f->total_len += write(1, "0", 1);
	}
	while (f->field_width-- > 1)
		f->total_len += write(1, " ", 1);
	f->total_len += write(1, &(n), 1);
}

static void	write_right_align(t_fmt *f, int n)
{
	f->total_len += write(1, &(n), 1);
	if (f->zero)
	{
		while (f->field_width-- > 1)
			f->total_len += write(1, "0", 1);
	}
	while (f->field_width-- > 1)
		f->total_len += write(1, " ", 1);
}

void		print_char(t_fmt *f, va_list ap)
{
	int n;

	n = (unsigned char)va_arg(ap, int);
	if (f->minus)
		write_right_align(f, n);
	else
		write_left_align(f, n);
}
