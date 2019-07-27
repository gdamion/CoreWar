/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:02:15 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	calc_lenl(long long n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_ltoa(long long n)
{
	int		count;
	char	*number;

	count = calc_lenl(n);
	if (n == 9223372036854775807 || n == 0)
		return (n == 0 ? ft_strdup("0") : ft_strdup("9223372036854775807"));
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!(number = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	number[count] = '\0';
	if (n < 0)
	{
		n *= -1;
		number[0] = '-';
	}
	while (n > 0 && (count-- > -1))
	{
		number[count] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}
