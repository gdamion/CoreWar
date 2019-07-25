/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:59:16 by tmann             #+#    #+#             */
/*   Updated: 2019/07/08 16:02:10 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_ltoa_base(unsigned long value, int base, short mode)
{
	char			*rep;
	char			*ptr;
	unsigned long	num;
	int				len;

	len = 0;
	rep = (mode == 1) ? ft_strdup("0123456789abcdef") :
	ft_strdup("0123456789ABCDEF");
	num = value;
	while (num /= base)
		len++;
	len = len + 1;
	ptr = (char*)malloc(sizeof(char) * len);
	ptr[len] = '\0';
	while (len > 0)
	{
		ptr[len - 1] = rep[value % base];
		value /= base;
		len--;
	}
	free(rep);
	return (ptr);
}
