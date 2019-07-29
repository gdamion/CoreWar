/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 21:24:16 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/07/16 13:07:57 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && ((unsigned char)*s1 == (unsigned char)*s2))
	{
		s1++;
		s2++;
	}
	return (((unsigned char)*s1 - (unsigned char)*s2));
}
