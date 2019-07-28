/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:56:26 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void			exec_live(t_carriage *carr, t_game *game)
{
	t_oper		oper;
	int			player_num;

	init_oper(&oper, carr->id);
	oper.i = carr->curr_position;
	change_oper_read_pos(&oper, 1);
	oper.arg1 = get_arg_value(game, oper.i + oper.j, 4);
	player_num = -1;
	player_num = find_player_by_num(game, (-1) * oper.arg1);
	if (player_num != -1)
	{
		game->champs[player_num]->die_player_circle = game->cycle_count;
		game->winner_num = player_num;
		game->champs[player_num]->live_coord = oper.i + oper.j;
		game->champs[player_num]->live_count++;
	}
	carr->last_live_check = game->cycle_count;
	game->live_checks_count++;
	change_oper_read_pos(&oper, 4);
	oper.i = carr->curr_position;
	move_carr(carr, oper.move_len);
	if (game->verbose)
		print_live(game, oper, player_num);
	else if (game->graphic)
		game->bright_arr[oper.i] = -game->cycle_count;
}
