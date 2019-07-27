/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 15:59:35 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	reverse_integ(char **str)
{
	int		i;
	int		j;
	char	tmp;

	i = 0;
	while ((*str)[i] && (*str)[i] != '.')
		i++;
	if (i == 0 || i == 1)
		return ;
	j = 0;
	i--;
	while (i > j)
	{
		tmp = (*str)[j];
		(*str)[j] = (*str)[i];
		(*str)[i] = tmp;
		j++;
		i--;
	}
}

void		move_str_right(char **str)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = ft_strdup(*str);
	i = 1;
	j = 0;
	(*str)[0] = ' ';
	while ((*str)[i])
	{
		(*str)[i] = tmp[j];
		i++;
		j++;
	}
	free(tmp);
}

void		print_rounded(t_fmt *f, char **str)
{
	int		r_prec;

	r_prec = f->precision;
	f->j = 0;
	while ((*str)[f->j] != '.')
		(f->j)++;
	while (r_prec--)
		(f->j)++;
	if (f->precision == 0)
	{
		round_prec_zero(f, str, 0);
		return ;
	}
	round_prec_all(f, str, 0);
}

static void	convert_fpart(char **str, int i, double fpart, int prec)
{
	unsigned long ipart;

	(*str)[i] = '.';
	reverse_integ(str);
	i++;
	while (prec--)
	{
		fpart *= 10;
		ipart = fpart;
		fpart = fpart - ipart;
		(*str)[i] = ipart + '0';
		i++;
	}
}

char		*double_to_str(long double num, int k_prec, int rem)
{
	char			*str;
	int				i;
	unsigned long	ipart;
	long double		fpart;

	str = (char*)malloc(sizeof(char) * 100 + k_prec);
	i = 0;
	if (num < 0)
		num *= -1;
	ipart = num;
	fpart = num - ipart;
	if (ipart == 0)
		str[i++] = '0';
	while (ipart)
	{
		rem = ipart % 10;
		str[i] = (rem + '0');
		ipart /= 10;
		i++;
	}
	convert_fpart(&str, i, fpart, k_prec);
	return (str);
}
