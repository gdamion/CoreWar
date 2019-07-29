/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:43:03 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/21 20:43:05 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0 || n > n + 1)
		return (0);
	while (*s1 && ((unsigned char)*s1 == (unsigned char)*s2) && --n)
	{
		s1++;
		s2++;
	}
	return (((unsigned char)*s1 - (unsigned char)*s2));
}
