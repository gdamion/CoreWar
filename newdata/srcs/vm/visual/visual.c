/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rywisozk <rywisozk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 13:18:19 by palan             #+#    #+#             */
/*   Updated: 2019/07/08 15:59:32 by rywisozk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vm.h"

void	draw_arena(t_game *game, t_carriage *carr)
{
	find_first_carr(carr);
	draw_code(game);
	draw_carrs(game, carr);
	draw_info(game, carr);
	draw_live_bar(game);
	draw_game_info(game);
	if (game->cycle_count == 0)
		pause_run(game, carr);
}

void	draw_info(t_game *game, t_carriage *carr)
{
	int		i;
	int		x;
	int		y;

	i = -1;
	draw_info_2(game, carr);
	while (++i < game->champs_count)
	{
		move(return_y(PL_ONE_LIVE) + i * 4 - 1, return_x(PL_ONE_LIVE));
		print_bold_str("Player -");
		addch(game->champs[i]->num + 48 | A_BOLD);
		print_bold_str(" : ");
		attron(COLOR_PAIR(i + 1));
		print_bold_str(game->champs[i]->name);
		attroff(COLOR_PAIR(i + 1));
		move(return_y(PL_ONE_LIVE) + i * 4, return_x(PL_ONE_LIVE) + 2);
		print_bold_str("Last live : ");
		print_nbr_ncurses(game->champs[i]->die_player_circle);
		move(return_y(PL_ONE_LIVE) + i * 4 + 1, return_x(PL_ONE_LIVE) + 2);
		print_bold_str("Lives in current period : ");
		nclean(5);
		print_nbr_ncurses(game->champs[i]->live_count);
	}
	getyx(stdscr, y, x);
	game->live_curr = ((y + 2) << 8) + x - 30;
}

void	draw_info_2(t_game *game, t_carriage *carr)
{
	move(return_y(RUNNING), return_x(RUNNING));
	print_bold_str("** RUNNING **");
	move(return_y(CYCLE_PER_SEC), return_x(CYCLE_PER_SEC));
	print_bold_str("Cycles/second limit : ");
	nclean(10);
	print_nbr_ncurses(game->cycles_per_sec);
	move(return_y(CYCLE_COORD), return_x(CYCLE_COORD));
	print_bold_str("Cycle : ");
	nclean(10);
	print_nbr_ncurses(game->cycle_count);
	move(return_y(PROCESSES), return_x(PROCESSES));
	print_bold_str("Processes : ");
	nclean(10);
	print_nbr_ncurses(count_carrs(carr));
}

void	draw_live_bar(t_game *game)
{
	int y;
	int x;

	move(return_y(game->live_curr), return_x(CYCLE_PER_SEC));
	print_bold_str("Live breakdown for current period :");
	move(return_y(game->live_curr) + 1, return_x(CYCLE_PER_SEC));
	draw_live_bar_for_each_champ(game, 1);
	move(return_y(game->live_curr) + 2, return_x(CYCLE_PER_SEC));
	print_bold_str("Live breakdown for last period :");
	move(return_y(game->live_curr) + 3, return_x(CYCLE_PER_SEC));
	draw_live_bar_for_each_champ(game, 2);
	getyx(stdscr, y, x);
	game->game_info = ((y + 2) << 8) + x - 50;
}

void	draw_game_info(t_game *game)
{
	move(return_y(game->game_info), return_x(CYCLE_PER_SEC));
	print_bold_str("CYCLE_TO_DIE : ");
	nclean(5);
	print_nbr_ncurses(game->cycle_to_die);
	move(return_y(game->game_info) + 2, return_x(CYCLE_PER_SEC));
	print_bold_str("CYCLE_DELTA : ");
	print_nbr_ncurses(game->cycle_delta);
	move(return_y(game->game_info) + 4, return_x(CYCLE_PER_SEC));
	print_bold_str("NBR_LIVE : ");
	print_nbr_ncurses(NBR_LIVE);
	move(return_y(game->game_info) + 6, return_x(CYCLE_PER_SEC));
	print_bold_str("MAX_CHECKS : ");
	print_nbr_ncurses(MAX_CHECKS);
	move(0, 0);
}
