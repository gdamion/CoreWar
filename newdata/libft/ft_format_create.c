/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:00:14 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_format(t_fmt *f)
{
	f->hash = 0;
	f->plus = 0;
	f->minus = 0;
	f->zero = 0;
	f->space = 0;
	f->precision = 0;
	f->len_modif = 0;
	f->have_prec = 0;
	f->field_width = 0;
	f->mode = 0;
	f->fl_sign = 0;
	f->is_pl = 0;
	f->was_m = 0;
}

void	set_jz_modif(const char *fmt, t_fmt *f)
{
	if (fmt[f->i] == 'j')
		f->len_modif = J;
	else if (fmt[f->i] == 'z')
		f->len_modif = Z;
}
