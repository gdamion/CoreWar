/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:14 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:17 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int			rounder(char *src, int i)
{
	while (i--)
	{
		if (src[i] == '9')
			src[i] = '0';
		else if ('0' <= src[i] && src[i] <= '8')
		{
			src[i]++;
			break ;
		}
		else
			break ;
	}
	return (i);
}

char				*round_it(char *src)
{
	int				i;

	i = ft_strlen(src) - 1;
	if ('5' <= src[i] && src[i] <= '9')
	{
		i = rounder(src, i);
		if (src[i] == '.')
			rounder(src, i);
	}
	src[ft_strlen(src) - 1] = '\0';
	return (src);
}

void				alignment_optput(t_specifier spec, char *src)
{
	int				len;

	len = (int)ft_strlen(src);
	if (!spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar_free(' ');
	ft_putstr_free(src);
	if (spec.flag_minus)
		while (len++ < spec.width)
			ft_putchar_free(' ');
}
