/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicates.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmaron-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 19:53:40 by lmaron-g          #+#    #+#             */
/*   Updated: 2019/05/20 19:53:42 by lmaron-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		duplicates(int *stack, int lenght)
{
	int	i;
	int	j;

	i = 0;
	while (i < lenght - 1)
	{
		j = i + 1;
		while (j < lenght)
		{
			if (stack[i] == stack[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
