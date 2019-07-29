/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unic.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:18:51 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:18:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void				ft_put_unicode(wchar_t c)
{
	if (c < 0x80)
		ft_putchar_free(c);
	else if (c < 0x800)
	{
		ft_putchar_free(c >> 6 | 0xC0);
		ft_putchar_free((c & 0x3F) | 0x80);
	}
	else if (c < 0x10000)
	{
		ft_putchar_free(c >> 12 | 0xE0);
		ft_putchar_free(((c >> 6) & 0x3F) | 0x80);
		ft_putchar_free((c & 0x3F) | 0x80);
	}
	else if (c < 0x110000)
	{
		ft_putchar_free(c >> 18 | 0xF0);
		ft_putchar_free(((c >> 12) & 0x3F) | 0x80);
		ft_putchar_free(((c >> 6) & 0x3F) | 0x80);
		ft_putchar_free((c & 0x3F) | 0x80);
	}
}

void				ft_put_unicode_str(wchar_t *src)
{
	int				i;

	i = 0;
	if (src)
	{
		while (src[i] != '\0')
			ft_put_unicode(src[i++]);
		ft_unicode_strdel(&src);
	}
}

int					ft_unicode_simblen(wchar_t c)
{
	int				len;

	len = 0;
	if (c < 0x80)
		len = 1;
	else if (c < 0x800)
		len = 2;
	else if (c < 0x10000)
		len = 3;
	else if (c < 0x110000)
		len = 4;
	return (len);
}

int					ft_unicode_strlen(wchar_t *src)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (src[i])
		len += ft_unicode_simblen(src[i++]);
	return (len);
}
