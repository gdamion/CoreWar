/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:08:29 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	calc_len_c(unsigned long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char		*ft_ultoa(unsigned long n)
{
	int		count;
	char	*number;

	count = calc_len_c(n);
	if (n == 9223372036854775807 || n == 0)
		return (n == 0 ? ft_strdup("0") : ft_strdup("9223372036854775807"));
	if (!(number = (char*)malloc(sizeof(char) * (count + 1))))
		return (NULL);
	number[count] = '\0';
	while (n > 0 && (count-- > -1))
	{
		number[count] = n % 10 + '0';
		n /= 10;
	}
	return (number);
}
