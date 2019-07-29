/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utilities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:38 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:39 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void					prec_zero(char **src, int precision)
{
	int					i;
	int					len;
	char				*new;

	i = 0;
	len = ft_strlen(*src);
	if (**src == '-')
		len--;
	if (precision && precision > len)
	{
		new = (char*)malloc(sizeof(char) * precision + 2);
		if (**src == '-')
		{
			new[i++] = '-';
			ft_strcpy(&new[precision + 1 - len], &(*src)[1]);
		}
		ft_strcpy(&new[precision - len], *src);
		while (len++ < precision)
			new[i++] = '0';
		ft_strdel(src);
		*src = new;
	}
}

void					add_zero(char **src, t_specifier spec)
{
	int					i;
	int					st;
	int					len;
	char				*new;

	i = 0;
	len = ft_strlen(*src);
	new = ft_strnew(spec.width);
	if (**src == '-' || **src == '+' || **src == ' ')
		*new = **src;
	if (**src == '0' && (*src)[1] == spec.type && spec.type)
		new = ft_strncpy(new, *src, 2);
	while (new[i])
		i++;
	st = i;
	while (len++ < spec.width)
		new[i++] = '0';
	ft_strcpy(&new[i], *src + st);
	ft_strdel(src);
	*src = new;
}

void					set_plus(char **src, t_specifier spec)
{
	char				*new;

	if (**src != '-' && spec.type != 'u')
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(*src) + 2);
		if (spec.flag_plus)
			new[0] = '+';
		else if (spec.flag_spase)
			new[0] = ' ';
		ft_strcpy(&new[1], *src);
		ft_strdel(src);
		*src = new;
	}
}

void					set_pref(char **src, char type)
{
	int					i;
	char				*new;

	i = 0;
	if (!(**src == '0' && (type == 'o' || type == 'O')))
	{
		new = (char*)malloc(sizeof(char) * ft_strlen(*src) + 3);
		new[i++] = '0';
		if (type == 'x' || type == 'X')
			new[i++] = type;
		ft_strcpy(&new[i], *src);
		ft_strdel(src);
		*src = new;
	}
}
