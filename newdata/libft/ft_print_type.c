/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:03:09 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_spec_symb(t_fmt *f)
{
	if (!f->minus)
	{
		while (f->field_width-- > 1)
			f->total_len += write(1, " ", 1);
	}
	f->total_len += write(1, "%", 1);
	if (f->minus)
	{
		while (f->field_width-- > 1)
			f->total_len += write(1, " ", 1);
	}
}

static void	print_big_dou(const char *fmt, t_fmt *f, va_list ap)
{
	if (fmt[f->i] == 'U')
	{
		f->len_modif = L;
		print_unsigned_decimal(f, ap);
	}
	else if (fmt[f->i] == 'D')
	{
		f->len_modif = L;
		print_decimal(f, ap);
	}
	else if (fmt[f->i] == 'O')
	{
		f->len_modif = L;
		print_octal(f, ap);
	}
}

void		print(const char *fmt, t_fmt *f, va_list ap)
{
	if (fmt[f->i] == 'd' || fmt[f->i] == 'i')
		print_decimal(f, ap);
	else if (fmt[f->i] == 'u')
		print_unsigned_decimal(f, ap);
	else if (fmt[f->i] == 'x' || fmt[f->i] == 'X')
		print_hex((fmt[f->i] == 'x' ? (short)1 : (short)2), f, ap);
	else if (fmt[f->i] == 'o')
		print_octal(f, ap);
	else if (fmt[f->i] == 'c')
		print_char(f, ap);
	else if (fmt[f->i] == 'f')
		print_floating_point(f, ap);
	else if (fmt[f->i] == 's')
		print_str(f, ap);
	else if (fmt[f->i] == 'p')
		print_ptr(f, ap);
	else if (fmt[f->i] == '%')
		print_spec_symb(f);
	else if (fmt[f->i] == 'D' || fmt[f->i] == 'O' || fmt[f->i] == 'U')
		print_big_dou(fmt, f, ap);
}
