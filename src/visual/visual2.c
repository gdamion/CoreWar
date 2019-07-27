/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmann <tmann@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:38:09 by tmann             #+#    #+#             */
/*   Updated: 2019/07/22 18:38:14 by tmann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	init_screen(t_game *game, t_carriage *carr)
{
	draw_arena(game, carr);
}

void	draw_code(t_game *game)
{
	int i;
	int j;

	j = 2;
	i = 0;
	move(j, 4);
	while (i < MEM_SIZE)
	{
		if (game->arena_which_champ[i] > 0 && game->arena_which_champ[i] < 5)
			attron(COLOR_PAIR(game->arena_which_champ[i]));
		if (check_bright(game, i))
			;
		else
		{
			if (game->arena[i] < 0x10)
				printw("0");
			printw("%hhx ", game->arena[i]);
		}
		if (game->arena_which_champ[i] != 0)
			attroff(COLOR_PAIR(game->arena_which_champ[i]));
		i++;
		if (i % 64 == 0)
			move(++j, 4);
	}
}

void	draw_carrs(t_game *game, t_carriage *carr)
{
	t_carriage	*tmp;
	int			y;
	int			x;

	tmp = carr;
	while (tmp)
	{
		if (tmp->is_alive)
		{
			y = tmp->curr_position / 64 + 2;
			x = 3 * (tmp->curr_position % 64) + 4;
			move(y, x);
			if (game->arena_which_champ[tmp->curr_position] != 0)
				attron(COLOR_PAIR(game->arena_which_champ
				[tmp->curr_position] + 4));
			else
				attron(COLOR_PAIR(10));
			if (game->arena[tmp->curr_position] < 0x10)
				printw("0");
			printw("%hhx", game->arena[tmp->curr_position]);
			attron(COLOR_PAIR(21));
		}
		tmp = tmp->prev;
	}
}
