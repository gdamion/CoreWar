/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:10:13 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		write_left_align(t_fmt *f, char *num, int num_len)
{
	int		i;
	int		pc;

	pc = f->field_width - f->precision;
	i = 0;
	while (f->zero && f->have_prec && f->field_width-- >= pc)
		f->total_len += write(1, "0", 1);
	while (f->zero && !f->have_prec && f->field_width-- > num_len)
		f->total_len += write(1, "0", 1);
	while (!f->zero && f->field_width-- > num_len)
		f->total_len += write(1, " ", 1);
	while (f->have_prec && f->field_width-- >= f->precision)
		f->total_len += write(1, " ", 1);
	while (f->have_prec && num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
	while (!f->have_prec && num[i])
		f->total_len += write(1, &num[i++], 1);
}

static void		write_right_align(t_fmt *f, char *num, int nl)
{
	int		i;
	int		pr;

	pr = f->precision;
	i = 0;
	while (f->have_prec && num[i] && f->precision--)
		f->total_len += write(1, &num[i++], 1);
	while (!f->have_prec && num[i])
		f->total_len += write(1, &num[i++], 1);
	while (f->have_prec && f->field_width-- > pr)
		f->total_len += write(1, " ", 1);
	while (f->field_width-- > ((nl == 0) ? (nl - f->have_prec) : nl))
		f->total_len += write(1, " ", 1);
}

void			print_str(t_fmt *f, va_list ap)
{
	char	*num;
	char	*s;
	int		num_len;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		f->total_len += write(1, "(null)", 6);
		return ;
	}
	num = ft_strdup(s);
	num_len = l_strlen(num);
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
