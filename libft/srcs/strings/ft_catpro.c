/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat_pro.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 21:57:23 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 21:57:31 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int						ft_catpro(char **dest, char *src)
{
	char				*ret;
	char				*fresh;
	char				*dst;

	ret = 0;
	dst = *dest;
	if (dst && src && (fresh = ft_strnew(ft_strlen(dst) + ft_strlen(src))))
	{
		ret = fresh;
		while (*dst)
			*fresh++ = (char)*dst++;
		while (*src)
			*fresh++ = (char)*src++;
	}
	else
		return (0);
	ft_strdel(dest);
	*dest = ret;
	return (1);
}

int						ft_catarg(char **dest, char *src)
{
	char				*ret;
	char				*fresh;
	char				*dst;

	ret = 0;
	dst = *dest;
	if (dst && src && (fresh = ft_strnew(ft_strlen(dst) + 1 + ft_strlen(src))))
	{
		ret = fresh;
		while (*dst)
			*fresh++ = (char)*dst++;
		*fresh++ = ' ';
		while (*src)
			*fresh++ = (char)*src++;
	}
	else
		return (0);
	ft_strdel(dest);
	*dest = ret;
	return (1);
}

int						ft_strmerge(char **dest, char **srcs)
{
	char				*ret;
	char				*fresh;
	char				*dst;
	char				*src;

	ret = 0;
	dst = *dest;
	src = *srcs;
	if (dst && src && (fresh = ft_strnew(ft_strlen(dst) + ft_strlen(src))))
	{
		ret = fresh;
		while (*dst)
			*fresh++ = (char)*dst++;
		while (*src)
			*fresh++ = (char)*src++;
	}
	else
		return (0);
	ft_strdel(dest);
	ft_strdel(srcs);
	*dest = ret;
	*srcs = src;
	return (1);
}
