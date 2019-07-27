/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_decimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:10:18 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t		calc_len_mod(t_fmt *f, va_list ap)
{
	uintmax_t n;

	if (f->len_modif == H)
		n = ((unsigned short)va_arg(ap, uintmax_t));
	else if (f->len_modif == HH)
		n = ((unsigned char)va_arg(ap, uintmax_t));
	else if (f->len_modif == L)
		n = (va_arg(ap, uintmax_t));
	else if (f->len_modif == LL)
		n = ((unsigned long long)va_arg(ap, uintmax_t));
	else if (f->len_modif == J)
		n = (va_arg(ap, uintmax_t));
	else if (f->len_modif == Z)
		n = (size_t)(va_arg(ap, uintmax_t));
	else
		n = (unsigned int)(va_arg(ap, uintmax_t));
	return (n);
}

static void				write_left_align(t_fmt *f, char *num, int num_len)
{
	int		i;
	int		pr_or_num;

	pr_or_num = (f->precision > num_len) ? f->precision : num_len;
	i = 0;
	if ((f->space || f->plus) && f->have_prec)
	{
		f->total_len += write(1, " ", 1);
		f->field_width--;
	}
	while (f->have_prec && f->field_width-- > pr_or_num)
		f->total_len += write(1, " ", 1);
	while (!f->zero && !f->have_prec && f->field_width-- > (num_len))
		f->total_len += write(1, " ", 1);
	while (f->zero && f->field_width-- > (num_len))
		f->total_len += write(1, "0", 1);
	while (f->precision-- > num_len)
		f->total_len += write(1, "0", 1);
	while (num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void				write_right_align(t_fmt *f, char *num, int num_len)
{
	int i;

	i = 0;
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
	while (f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
}

void					print_unsigned_decimal(t_fmt *f, va_list ap)
{
	uintmax_t		n;
	char			*num;
	int				num_len;

	n = calc_len_mod(f, ap);
	num = ft_ultoa(n);
	num_len = l_strlen(num);
	if (n == 0 && f->have_prec && f->precision == 0 && f->field_width == 0)
		return ;
	f->pmf = (f->precision > f->field_width) ? 1 : 0;
	if (f->minus)
		f->zero = 0;
	if (f->plus)
		f->space = 0;
	if (f->minus)
		write_right_align(f, num, num_len);
	else
		write_left_align(f, num, num_len);
	free(num);
}
