/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_lenghts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:27:25 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 15:27:36 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

long long int		use_lenght_for_di(t_specifier spec, va_list ap)
{
	if (spec.length == 1 || spec.type == 'D')
		return (va_arg(ap, long));
	if (spec.length == 10)
		return (va_arg(ap, long long));
	if (spec.length == 2)
		return ((short int)va_arg(ap, int));
	if (spec.length == 20)
		return ((char)va_arg(ap, int));
	if (spec.length == 4)
		return (va_arg(ap, size_t));
	if (spec.length == 5)
		return (va_arg(ap, long));
	return (va_arg(ap, int));
}

long long int		use_lenght_for_uoxx(t_specifier spec, va_list ap)
{
	if (spec.length == 1 || spec.type == 'O' || spec.type == 'U')
		return (va_arg(ap, unsigned long int));
	if (spec.length == 10)
		return (va_arg(ap, unsigned long long int));
	if (spec.length == 2)
		return ((unsigned short int)va_arg(ap, unsigned int));
	if (spec.length == 20)
		return ((unsigned char)va_arg(ap, unsigned int));
	if (spec.length == 4)
		return (va_arg(ap, size_t));
	if (spec.length == 5)
		return (va_arg(ap, long));
	return (va_arg(ap, unsigned int));
}

long double			use_lenght_for_f(t_specifier spec, va_list ap)
{
	if ((spec.length == 3 && spec.type == 'f'))
		return (va_arg(ap, long double));
	return (va_arg(ap, double));
}

void				print_strings(t_specifier spec, va_list ap)
{
	if (spec.type == 's' && spec.length != 1)
		print_specifier_s(spec, ap);
	if (spec.type == 'S' || (spec.type == 's' && spec.length == 1))
		print_specifier_l_s(spec, ap);
}

void				print_chars(t_specifier spec, va_list ap)
{
	if ((spec.type == '%') || (spec.type == 'c' && spec.length != 1))
		print_specifier_c(spec, ap);
	if (spec.type == 'C' || (spec.type == 'c' && spec.length == 1))
		print_specifier_l_c(spec, ap);
}
