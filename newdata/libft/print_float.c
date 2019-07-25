/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:09:07 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double	calc_len_mod(t_fmt *f, va_list ap)
{
	long double n;

	if (f->len_modif == L)
		n = (double)(va_arg(ap, double));
	else if (f->len_modif == LL)
		n = (va_arg(ap, long double));
	else
		n = (double)(va_arg(ap, double));
	return (n);
}

int					count_before_dot(char *num)
{
	int i;

	i = 0;
	while (num[i] && num[i] != '.')
		i++;
	return (i + 1);
}

static void			write_left_align(t_fmt *f, char *num,
long double n)
{
	int		i;
	int		ismin;

	ismin = (n < 0) ? 1 : 0;
	print_rounded(f, &num);
	i = 0;
	if (f->zero && ismin && !f->plus && f->field_width--)
		f->total_len += write(1, "-", 1);
	if (f->zero && f->plus && f->field_width--)
		f->total_len += write(1, ((n < 0) ? "-" : "+"), 1);
	while (f->zero && f->field_width-- > f->precision + count_before_dot(num))
		f->total_len += write(1, "0", 1);
	while (!f->zero && f->field_width-- > f->precision
	+ count_before_dot(num) + (f->plus || ismin))
		f->total_len += write(1, " ", 1);
	if (!f->zero && ismin && !f->plus && f->field_width--)
		f->total_len += write(1, "-", 1);
	if (!f->zero && f->plus && f->field_width--)
		f->total_len += write(1, ((n < 0) ? "-" : "+"), 1);
	while (num[i] && num[i] != '.')
		f->total_len += write(1, &num[i++], 1);
	if (f->hash || (!f->hash && f->precision))
		f->total_len += write(1, &num[i++], 1);
	while (num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
}

static void			write_right_align(t_fmt *f, char *num,
long double n)
{
	int		i;
	int		ismin;
	int		prec;

	prec = f->precision;
	i = 0;
	ismin = (n < 0) ? 1 : 0;
	print_rounded(f, &num);
	if (ismin && !f->plus && f->field_width--)
		f->total_len += write(1, "-", 1);
	if (f->plus && f->field_width--)
		f->total_len += write(1, ((n < 0) ? "-" : "+"), 1);
	while (num[i] && num[i] != '.')
		f->total_len += write(1, &num[i++], 1);
	if (f->hash || (!f->hash && f->precision))
		f->total_len += write(1, &num[i++], 1);
	while (num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
	while (f->field_width-- > prec
	+ count_before_dot(num))
		f->total_len += write(1, " ", 1);
}

void				print_floating_point(t_fmt *f, va_list ap)
{
	long double	n;
	char		*num;
	int			num_len;

	n = calc_len_mod(f, ap);
	if (n < 0)
		f->fl_sign = 1;
	if (!f->have_prec)
		f->precision = 6;
	num = double_to_str(n, f->precision + 20, 0);
	num_len = l_strlen(num);
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->minus)
		write_right_align(f, num, n);
	else
	{
		if (!f->plus && f->zero && f->space && n >= 0 && f->field_width--)
			f->total_len += write(1, " ", 1);
		write_left_align(f, num, n);
	}
	free(num);
}
