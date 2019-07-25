/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:01:15 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(long value, int base, short mode)
{
	char	*rep;
	char	*ptr;
	long	num;
	int		len;
	int		flag;

	len = 0;
	flag = (value < 0 ? 1 : 0);
	rep = (mode == 1) ? ft_strdup("0123456789abcdef") :
	ft_strdup("0123456789ABCDEF");
	num = value;
	while (num /= base)
		len++;
	len = len + flag + 1;
	ptr = (char*)malloc(sizeof(char) * len);
	ptr[len] = '\0';
	if (flag == 1)
		ptr[0] = '-';
	while (--len > flag)
	{
		ptr[len - 1] = rep[value % base];
		value /= base;
	}
	free(rep);
	return (ptr);
}
