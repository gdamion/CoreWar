/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 22:12:21 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:26 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int				ft_consist(const char *str, const char *sub)
{
	size_t		n;

	n = ft_strlen((char*)sub);
	if (!ft_memcmp(str, sub, n))
		return (n);
	return (0);
}

int				scan_color(char *src)
{
	int			i;

	i = 0;
	if ((i += ft_consist(src, "{RED}")))
		ft_printf(RED);
	else if ((i += ft_consist(src, "{BLACK}")))
		ft_printf(BLACK);
	else if ((i += ft_consist(src, "{WHITE}")))
		ft_printf(WHITE);
	else if ((i += ft_consist(src, "{YELLOW}")))
		ft_printf(YELLOW);
	else if ((i += ft_consist(src, "{PURPUL}")))
		ft_printf(PURPUL);
	else if ((i += ft_consist(src, "{GREEN}")))
		ft_printf(GREEN);
	else if ((i += ft_consist(src, "{RED}")))
		ft_printf(RED);
	else if ((i += ft_consist(src, "{BLUE}")))
		ft_printf(BLUE);
	else if ((i += ft_consist(src, "{CYAN}")))
		ft_printf(CYAN);
	else if ((i += ft_consist(src, "{EOC}")))
		ft_printf(EOC);
	return (i);
}

void			use_specifier(t_specifier spec, va_list ap)
{
	if (spec.type == 'd' || spec.type == 'D' || spec.type == 'i')
		print_specifier_di(spec, use_lenght_for_di(spec, ap));
	if (spec.type == 'o' || spec.type == 'O')
		print_specifier_o(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'u' || spec.type == 'U')
		print_specifier_u(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'x' || spec.type == 'X')
		print_specifier_x(spec, use_lenght_for_uoxx(spec, ap));
	if (spec.type == 'f' || spec.type == 'F')
		print_specifier_f(spec, use_lenght_for_f(spec, ap));
	if (spec.type == 's' || spec.type == 'S')
		print_strings(spec, ap);
	if (spec.type == 'c' || spec.type == 'C' || spec.type == '%')
		print_chars(spec, ap);
	if (spec.type == 'p')
		print_specifier_p(spec, ap);
	if (spec.type == 'W' || (spec.type == 'w' && spec.length == 1))
		print_specifier_l_w(spec, ap);
	if (spec.type == 'w' && spec.length != 1)
		print_specifier_w(spec, ap);
	if (spec.type == 'b')
		print_specifier_b(spec, use_lenght_for_uoxx(spec, ap));
}

int				scan_specifier(char *src, va_list ap)
{
	int			i;
	t_specifier	spec;

	i = 0;
	find_flags(&spec, src);
	spec.width = find_width(src, ap);
	spec.length = find_lenght(src);
	spec.precision = find_precision(src, ap);
	while (src[i] && is_right(src[i]) && !is_type(src[i]))
		i++;
	if (!is_type(src[i]))
		return (0);
	spec.type = src[i];
	use_specifier(spec, ap);
	return (i + 1);
}

int				ft_printf(char *src, ...)
{
	int			i;
	va_list		ap;

	i = 0;
	g_r = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '{')
			i += scan_color(&src[i]);
		if (src[i] == '%')
			i += scan_specifier(&src[i + 1], ap);
		else
			ft_putchar_free(src[i]);
		i++;
	}
	return (g_r);
}
