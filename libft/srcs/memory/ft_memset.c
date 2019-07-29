/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:42:09 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/20 15:42:10 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*uc;

	i = 0;
	uc = (unsigned char*)b;
	while (i < len)
		uc[i++] = (unsigned char)c;
	return (uc);
}
