/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 15:57:55 by rywisozk          #+#    #+#             */
/*   Updated: 2019/07/27 18:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "corewar.h"

void		free_game(t_game *game)
{
	if (game->arena)
		free(game->arena);
	if (game->arena_which_champ)
		free(game->arena_which_champ);
	if (game->bright_arr)
		free(game->bright_arr);
}

void		free_champs(t_game *game)
{
	int		i;

	i = 0;
	while (i < game->champs_count)
	{
		free(game->champs[i]->name);
		free(game->champs[i]->comment);
		free(game->champs[i]->exec);
		free(game->champs[i]);
		i++;
	}
	free(game->champs);
}

void		free_carrs(t_carriage **head)
{
	t_carriage *tmp;
	t_carriage *curr;

	tmp = *head;
	while (tmp)
	{
		curr = tmp;
		tmp = tmp->next;
		free(curr);
	}
}

void		free_binary_presentation(t_binary_r *file)
{
	if (file->arr)
		free(file->arr);
	if (file->used_num_names)
		free(file->used_num_names);
}
