/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decimal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:09:03 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static intmax_t	calc_len_mod(t_fmt *f, va_list ap)
{
	intmax_t n;

	if (f->len_modif == H)
		n = ((short)va_arg(ap, intmax_t));
	else if (f->len_modif == HH)
		n = ((char)va_arg(ap, intmax_t));
	else if (f->len_modif == L)
		n = (va_arg(ap, intmax_t));
	else if (f->len_modif == LL)
		n = ((long long)va_arg(ap, intmax_t));
	else if (f->len_modif == Z)
		n = ((long)va_arg(ap, intmax_t));
	else if (f->len_modif == J)
		n = (va_arg(ap, intmax_t));
	else
		n = (int)(va_arg(ap, intmax_t));
	return (n);
}

static void		write_left_after_flags(t_fmt *f, char *num,
intmax_t n, int num_len)
{
	int i;
	int	prec_mo;

	prec_mo = (f->precision > 0) ? 1 : 0;
	i = (n < 0) ? 1 : 0;
	if (f->plus && ((f->precision >= num_len) || f->zero))
	{
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
		f->is_pl = 1;
	}
	while (!f->zero && !f->have_prec && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (f->zero && f->field_width-- > num_len)
		f->total_len += write(1, "0", 1);
	while (f->precision-- > (num_len))
		f->total_len += write(1, "0", 1);
	if (f->plus && f->have_prec == 0 && f->is_pl == 0)
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (!f->zero && n < 0 && f->is_pl == 0)
		f->total_len += write(1, "-", 1);
	while (num[i] && (!f->have_prec || (n != 0 ||
	f->precision > 0) || (n == 0 && prec_mo)))
		f->total_len += write(1, &num[i++], 1);
}

static void		write_left_align(t_fmt *f, char *num, intmax_t n, int num_len)
{
	int pr_or_num;

	pr_or_num = (f->precision > num_len) ? f->precision : num_len;
	f->is_pl = 0;
	if (f->have_prec && !f->precision && n == 0 && f->field_width > 0)
		f->total_len += write(1, " ", 1);
	while (f->have_prec && f->field_width-- > (pr_or_num))
		f->total_len += write(1, " ", 1);
	if (f->space && !f->plus && n >= 0)
		f->total_len += write(1, " ", 1);
	if (!f->plus && (f->zero || f->have_prec) && n < 0 && !f->is_pl++)
		f->total_len += write(1, "-", 1);
	write_left_after_flags(f, num, n, num_len);
}

static void		write_right_align(t_fmt *f, char *num, intmax_t n, int num_len)
{
	int i;

	i = (n < 0) ? 1 : 0;
	if (f->plus)
		f->total_len += write(1, ((num[0] == '-') ? "-" : "+"), 1);
	else if (n < 0)
		f->total_len += write(1, "-", 1);
	if (f->precision > num_len)
	{
		while (f->precision-- > (num_len))
		{
			f->total_len += write(1, "0", 1);
			f->field_width--;
		}
	}
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
	while (!f->pmf && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
}

void			print_decimal(t_fmt *f, va_list ap)
{
	intmax_t	n;
	char		*num;
	int			num_len;

	n = calc_len_mod(f, ap);
	num = ft_ltoa(n);
	num_len = l_strlen(num);
	f->pmf = (f->precision > f->field_width) ? 1 : 0;
	if (f->minus || f->have_prec)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	else if (f->space)
		f->field_width--;
	if (f->plus || n < 0)
	{
		f->field_width--;
		if (n < 0)
			num_len--;
	}
	if (f->minus)
		write_right_align(f, num, n, num_len);
	else
		write_left_align(f, num, n, num_len);
	free(num);
}
