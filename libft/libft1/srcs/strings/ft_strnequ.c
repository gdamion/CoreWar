/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:15:46 by lmaron-g          #+#    #+#             */
/*   Updated: 2018/11/22 21:15:54 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (n > n + 1)
		return (0);
	if (s1 && s2)
		if (!ft_strncmp(s1, s2, n))
			return (1);
	return (0);
}
