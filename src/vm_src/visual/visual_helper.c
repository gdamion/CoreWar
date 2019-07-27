/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:36:59 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void	array_index_to_move_coord(int *y, int *x, int arr_index)
{
	*y = arr_index / 64 + 2;
	*x = 3 * (arr_index % 64) + 4;
}

/*
** which_lives :
** 1 - for current
** 2 - for prev
*/

void	draw_live_bar_for_each_champ(t_game *game, int which_lives)
{
	which_lives == 1 ? draw_curr_lives(game) : draw_prev_lives(game);
}

void	process_keyboard(t_game *game, t_carriage *carr, char ch)
{
	if (ch == ' ')
		pause_run(game, carr);
	else if (ch == '1')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 1 : 500;
	else if (ch == '4')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 10 : 500;
	else if (ch == '7')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 100 : 500;
	else if (ch == '3')
		game->cycles_per_sec = (game->cycles_per_sec > 5) ?
		game->cycles_per_sec - 1 : 5;
	else if (ch == '6')
		game->cycles_per_sec = (game->cycles_per_sec > 10) ?
		game->cycles_per_sec - 10 : 5;
	else if (ch == '9')
		game->cycles_per_sec = (game->cycles_per_sec > 100) ?
		game->cycles_per_sec - 100 : 5;
	draw_info(game, carr);
	if (game->cycles_per_sec != 500)
		usleep(600000 / (game->cycles_per_sec * 3));
}

void	pause_run(t_game *game, t_carriage *carr)
{
	move(return_y(RUNNING), return_x(RUNNING));
	print_bold_str("** PAUSED ** ");
	while (work_with_speed_when_paused(game, getch()))
	{
		draw_info(game, carr);
		move(return_y(RUNNING), return_x(RUNNING));
		print_bold_str("** PAUSED ** ");
	}
}

int		work_with_speed_when_paused(t_game *game, char ch)
{
	if (ch == '1')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 1 : 500;
	else if (ch == '4')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 10 : 500;
	else if (ch == '7')
		game->cycles_per_sec = (game->cycles_per_sec < 500) ?
		game->cycles_per_sec + 100 : 500;
	else if (ch == '3')
		game->cycles_per_sec = (game->cycles_per_sec > 5) ?
		game->cycles_per_sec - 1 : 5;
	else if (ch == '6')
		game->cycles_per_sec = (game->cycles_per_sec > 10) ?
		game->cycles_per_sec - 10 : 5;
	else if (ch == '9')
		game->cycles_per_sec = (game->cycles_per_sec > 100) ?
		game->cycles_per_sec - 100 : 5;
	else if (ch == ' ')
		return (0);
	return (1);
}
