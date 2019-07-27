/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 18:35:09 by tmann             #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

int			find_player_by_num(t_game *game, int num)
{
	int	i;

	i = 0;
	while (i < game->champs_count)
	{
		if (game->champs[i]->num == num)
			return (i);
		i++;
	}
	return (-1);
}

void		reset_live_count_of_players(t_game *game)
{
	int i;

	i = 0;
	while (i < game->champs_count)
	{
		game->champs[i]->prev_live_count = game->champs[i]->live_count;
		game->champs[i]->live_count = 0;
		i++;
	}
}

t_player	*init_player(int player_number)
{
	t_player *player;

	if (!(player = malloc(sizeof(t_player))))
		exit(-1);
	ft_bzero(player, sizeof(t_player));
	player->num = player_number;
	player->live_count = 0;
	return (player);
}

t_player	*prepare_player(t_binary_r *file, int player_number)
{
	t_player *player;

	check_magic_header(file);
	check_null(file);
	player = init_player(player_number);
	player->name = get_champ_name(file);
	player->exec_size = get_champ_exec_code_size(file);
	player->comment = get_champ_comment(file);
	player->exec = get_champ_exec(file, player->exec_size);
	player->die_player_circle = 0;
	player->live_coord = 0;
	player->live_count = 0;
	player->prev_live_count = 0;
	check_exec_size(player);
	compare_exec_with_size(player->exec_size, file->size);
	return (player);
}

t_player	**init_champs(t_player **champs, t_player *new_pl)
{
	int			i;
	t_player	**new_champs;

	new_champs = champs;
	if (new_pl == NULL)
		return (NULL);
	if (new_champs == NULL)
	{
		if (!(new_champs = malloc(sizeof(t_player*) * (2))))
			exit(-1);
		new_champs[0] = new_pl;
		new_champs[1] = NULL;
		return (new_champs);
	}
	i = 0;
	while (new_champs[i])
		i++;
	i = i + 1;
	if (!(new_champs = realloc(new_champs, (i + 1) * sizeof(t_player*))))
		exit(-1);
	new_champs[i - 1] = new_pl;
	new_champs[i] = NULL;
	return (new_champs);
}
