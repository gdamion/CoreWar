/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:04:37 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/07/18 17:20:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define A(c) (c == ' ')
#define B(c) (c == '\n')
#define C(c) (c == '\t')
#define D(c) (c == '\v')
#define I(c) (c == '\f')
#define F(c) (c == '\r')

#define ERR_ATOI "ERROR: Invalid number"
#define SP(c) (A(c) || B(c) || C(c) || D(c) || I(c) || F(c))

#include "libft.h"

int					ft_isdigit_base(char c, int base)
{
	const char		*alphabet = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (i < base)
	{
		if (alphabet[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

_Bool				ft_has_prefix(const char *str, int base)
{
	size_t			i;

	i = 0;
	if (base == 2 || base == 8 || base == 16)
	{
		if (str[i++] != '0')
			return (FALSE);
		if (base == 2 && (str[i] == 'b' || str[i] == 'B'))
			return (TRUE);
		if (base == 16 && (str[i] == 'x' || str[i] == 'X'))
			return (TRUE);
		if (base == 8)
			return (TRUE);
	}
	return (FALSE);
}

_Bool				ft_isnumber_base(char *str, int base)
{
	size_t			i;
	size_t			digits;

	i = 0;
	digits = 0;
	while (SP(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (FALSE);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (ft_isdigit_base(str[i], base) >= 0)
	{
		i++;
		digits++;
	}
	return ((!str[i] && digits) ? TRUE : FALSE);
}

int					ft_atoi_base(const char *str, int base)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	result = 0;
	i = 0;
	sign = 1;
	while (SP(str[i]))
		i++;
	if (base != 10 && !ft_has_prefix(&str[i], base))
		return (FALSE);
	if (base == 2 || base == 16)
		i += 2;
	else if (base == 8)
		i++;
	else if (base == 10 && (str[i] == '-' || str[i] == '+'))
		sign = (str[i++] == '-') ? -1 : 1;
	while (ft_isdigit_base(str[i], base) >= 0)
		result = result * base + ft_isdigit_base(str[i++], base);
	return ((int)(result * sign));
}

int					ft_atoi(const char *str)
{
	int				neg;
	int				i;
	long long int	num;

	i = 0;
	neg = 0;
	num = 0;
	while (SP(str[i]))
		i++;
	if (str[i] == 45)
		neg = 1;
	if ((str[i] == 45) || (str[i] == 43))
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		num *= 10;
		num += ((int)str[i] - 48);
		if (num < MIN_INT || MAX_INT < num)
			print_error(ERR_ATOI);
		i++;
	}
	return (neg == 1 ? -num : num);
}
