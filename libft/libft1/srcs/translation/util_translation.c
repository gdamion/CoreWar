/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_translation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 17:20:15 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/01/07 17:20:17 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char					*ft_itoa_ll(long long int n)
{
	long long int		i;
	long long int		sign;
	unsigned long long	nbr;
	char				*str;

	sign = 0;
	nbr = n;
	if (n < 0)
	{
		sign = 1;
		nbr = -n;
	}
	i = ft_nbrlen_u(nbr) + sign;
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	while (--i >= sign)
	{
		str[i] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

char					*ft_itoa_ull(unsigned long long nb)
{
	char				*str;
	unsigned long long	nbr;
	int					i;

	i = 0;
	if (!(str = (char*)malloc(sizeof(char) * ft_nbrlen_u(nb) + 1)))
		return (NULL);
	nbr = nb;
	str[ft_nbrlen_u(nb) - i++] = '\0';
	while (nbr >= 10)
	{
		str[ft_nbrlen_u(nb) - i++] = (nbr % 10) + 48;
		nbr /= 10;
	}
	str[ft_nbrlen_u(nb) - i++] = (nbr % 10) + 48;
	return (str);
}

char					*ft_itoa_base(int dec, int base, int up)
{
	int					len;
	char				*nbr;
	int					neg;

	neg = 0;
	len = 1;
	if (dec < 0)
		dec *= -1;
	while ((int)ft_pow(base, len) - 1 < dec)
		len++;
	nbr = (char*)malloc(sizeof(char*) * len);
	nbr[len + neg] = '\0';
	while (len-- > 0)
	{
		if (!up)
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'a' - 10 : '0');
		else
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'A' - 10 : '0');
		dec = dec / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

char					*ft_itoa_base_ull(unsigned long long dec,
						int base, char x)
{
	int					len;
	char				*nbr;
	int					neg;

	neg = 0;
	len = 1;
	while (ft_pow(base, len) - 1 < dec)
		len++;
	nbr = (char*)malloc(sizeof(char*) * len);
	nbr[len + neg] = '\0';
	while (len-- > 0)
	{
		if (x == 'x')
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'a' - 10 : '0');
		else
			nbr[len + neg] = (dec % base) + (dec % base > 9 ? 'A' - 10 : '0');
		dec = dec / base;
	}
	if (neg)
		nbr[0] = '-';
	return (nbr);
}

/*
**char					*ft_ftoa(long double n, int precision)
**{
**	long				i;
**	char				*s1;
**	char				*s2;
**	unsigned char		trans;
**
**	i = 0;
**	if (IS_INF(n))
**		return (ft_strdup("inf"));
**	if (IS_NAN(n))
**		return (ft_strdup("nan"));
**	s1 = ft_itoa_ll((long)n);
**	s2 = ft_strnew(++precision);
**	ft_cat_pro(&s1, ".");
**	n *= (n < 0.0) ? -1 : 1;
**	n -= (long)n;
**	while (precision--)
**	{
**		n *= 10.0;
**		trans = (long int)n;
**		s2[i++] = trans | 0x30;
**		n -= (double)trans;
**	}
**	ft_cat_pro(&s1, s2);
**	ft_strdel(&s2);
**	return (round_it(s1));
**}
*/

char					*ft_ftoa(long double n, int precision)
{
	long				i;
	char				*s1;
	char				*s2;
	unsigned char		trans;

	i = 0;
	n *= n < 0.0 ? -1 : 1;
	s1 = n < 0.0 ? ft_strdup("-") : ft_strdup("");
	s2 = ft_itoa_ll(FT_ABS((long)n));
	ft_strmerge(&s1, &s2);
	s2 = ft_strnew(++precision);
	ft_catpro(&s1, ".");
	n -= (long)n;
	while (precision--)
	{
		n *= 10.0;
		trans = (long int)n;
		s2[i++] = trans | 0x30;
		n -= (double)trans;
	}
	ft_strmerge(&s1, &s2);
	return (round_it(s1));
}
