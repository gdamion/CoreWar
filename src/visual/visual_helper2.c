/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:37:18 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:37:30 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

int			count_carrs(t_carriage *carr)
{
	t_carriage	*tmp;
	int			i;

	i = 0;
	tmp = find_first_carr(carr);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

t_carriage	*find_first_carr(t_carriage *carr)
{
	int i;

	i = 0;
	if (!carr)
		return (NULL);
	while (carr->prev)
		carr = carr->prev;
	return (carr);
}

int			return_y(int coord)
{
	return ((coord & 0xff << 8) >> 8);
}

int			return_x(int coord)
{
	return (coord & 0xff);
}

void		add_coordination_live(t_player *pl, int y, int x)
{
	pl->live_coord = pl->live_coord | y << 8;
	pl->live_coord = pl->live_coord | x;
}
