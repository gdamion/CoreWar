/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 16:36:56 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/12/27 16:37:00 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				print_specifier_di(t_specifier spec, long long int nbr)
{
	char			*src;

	if (nbr == 0 && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_ll(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_plus || spec.flag_spase)
		set_plus(&src, spec);
	if (spec.flag_zero && !spec.flag_minus && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	alignment_optput(spec, src);
}

void				print_specifier_o(t_specifier spec, unsigned long long nbr)
{
	char			*src;

	if (!nbr && spec.precision == -1 && !spec.flag_hash)
		src = ft_strnew(0);
	else
		src = ft_itoa_base_ull(nbr, 8, spec.type);
	prec_zero(&src, spec.precision);
	if (spec.flag_hash && nbr)
		set_pref(&src, spec.type);
	if (spec.flag_zero && !spec.flag_minus && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	alignment_optput(spec, src);
}

void				print_specifier_u(t_specifier spec, unsigned long long nbr)
{
	char			*src;

	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_ull(nbr);
	prec_zero(&src, spec.precision);
	if (spec.flag_plus || spec.flag_spase)
		set_plus(&src, spec);
	if (spec.flag_zero && !spec.flag_minus && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	alignment_optput(spec, src);
}

void				print_specifier_x(t_specifier spec, unsigned long long nbr)
{
	char			*src;

	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_base_ull(nbr, 16, spec.type);
	prec_zero(&src, spec.precision);
	if (spec.flag_hash && nbr)
		set_pref(&src, spec.type);
	if (spec.flag_zero && !spec.flag_minus && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	alignment_optput(spec, src);
}

void				print_specifier_b(t_specifier spec, unsigned long long nbr)
{
	char			*src;

	if (!nbr && spec.precision == -1)
		src = ft_strnew(0);
	else
		src = ft_itoa_base_ull(nbr, 2, spec.type);
	prec_zero(&src, spec.precision);
	if (spec.flag_hash && nbr)
		set_pref(&src, spec.type);
	if (spec.flag_zero && !spec.flag_minus && !spec.precision)
		if ((int)ft_strlen(src) < spec.width)
			add_zero(&src, spec);
	alignment_optput(spec, src);
}
