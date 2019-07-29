/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cusu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:51 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

wchar_t				*ft_unicode_precision(wchar_t *src, int precision)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	if (precision == -1)
		src[0] = '\0';
	if (precision > 0)
		while (src[i])
		{
			len += ft_unicode_simblen(src[i]);
			if (len > precision)
				src[i] = '\0';
			i++;
		}
	return (src);
}

void				print_specifier_l_s(t_specifier spec, va_list ap)
{
	wchar_t			*src;
	int				len;

	len = 0;
	if (!(src = va_arg(ap, wchar_t*)))
		src = ft_unicode_strdup(L"(null)");
	src = ft_unicode_precision(ft_unicode_strdup(src), spec.precision);
	len = ft_unicode_strlen(src);
	if (!spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar_free(' ');
	ft_put_unicode_str(src);
	if (spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar_free(' ');
}

void				print_specifier_l_c(t_specifier spec, va_list ap)
{
	wchar_t			c;
	int				len;

	c = va_arg(ap, wchar_t);
	len = ft_unicode_simblen(c);
	if (!spec.flag_minus && spec.width)
		while (len++ < spec.width)
			ft_putchar_free(' ');
	ft_put_unicode(c);
	if (spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar_free(' ');
}

void				print_specifier_l_w(t_specifier spec, va_list ap)
{
	wchar_t			**src;
	int				len;
	int				i;

	i = 0;
	len = 0;
	src = va_arg(ap, wchar_t**);
	while (src[i])
	{
		src[i] = ft_unicode_strdup(src[i]);
		src[i] = ft_unicode_precision(src[i], spec.precision);
		if (spec.width)
			len = ft_unicode_strlen(src[i]);
		if (!spec.flag_minus)
			while (len++ < spec.width)
				ft_putchar_free(' ');
		ft_put_unicode_str(src[i]);
		if (spec.flag_minus)
			while (len++ < spec.width)
				ft_putchar_free(' ');
		ft_putchar_free('\n');
		i++;
	}
}
