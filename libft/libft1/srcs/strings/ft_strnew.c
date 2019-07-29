/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:58:24 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/07/11 16:39:41 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char		*ft_strnew(size_t size)
{
	if (size == SIZE_T_MAX)
		print_error("ft_strnew: incorrect size");
	return ((char *)ft_memalloc(sizeof(char) * (size + 1)));
}
