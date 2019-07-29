/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:54:42 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 12:54:45 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	void	*ptr;

	if (size == SIZE_T_MAX)
		size--;
	if ((ptr = malloc(size)))
		ft_bzero(ptr, size);
	return (ptr);
}
